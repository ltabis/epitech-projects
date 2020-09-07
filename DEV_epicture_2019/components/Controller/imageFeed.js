/**
 * Creating flatlist for the feed page
 *
 *
 * @format
 * @flow
 */

import React from 'react';
import { FlatList } from 'react-native';

import ImageBlock from '../View/modules/imageBlock'

class ImageFeed extends React.Component {

  //Get images state from Imgur API
  constructor(props) {
      super(props);
      this.state = {
          imageList: [],
          fetchUrl: this.props.fetchUrl,
          apiKey: this.props.apiKey,
          access: this.props.access,
        };
        this.constructMedia = this.constructMedia.bind(this);
        this.fetchData = this.fetchData.bind(this);
      }

  fetchData = (fetchUrl, apiKey, access) => {
    fetch(fetchUrl, {
      method: 'GET',
      headers: {
          'Authorization': access + ' ' + apiKey,
      },
      }).then(response => response.json())
      .then(data => {
        const tmpList = [];
        data.data.map(( image ) => {
          if (image.images_count !== undefined || access == 'Bearer') {
                tmpList.push(image);
            }
          })
          this.setState({ imageList: tmpList })
      }).catch(error => { console.log(error) })
  }

  constructMedia = (item, access) => {
    try {
      if (access == 'Bearer') {
        return (
          <ImageBlock title={ item.title } id={ item.id } link={ item.link }/>
        );
      }
      if (item.images[0].link.split('.').pop() == 'jpg' || item.images[0].link.split('.').pop() == 'png') {
        return (
          <ImageBlock title={ item.title } id={ item.id } link={ item.images[0].link }/>
        );
      }
    } catch (error) {
      alert(error)
    }
  }

  componentDidUpdate(nextProps) {
    if (nextProps.fetchUrl !== this.state.fetchUrl) {
      this.setState((state) => ({ fetchUrl: nextProps.fetchUrl,
                                  imageList: this.fetchData(nextProps.fetchUrl, state.apiKey, this.state.access) }))
    }
  }

  componentDidMount() {
    this.setState((props) => ({ imageList: this.fetchData(props.fetchUrl, props.apiKey, this.state.access) }));
  }

  render() {

    return (
      <FlatList
          data={ this.state.imageList }
          renderItem={({ item }) => {
            return (
              this.constructMedia(item, this.state.access)
            );
          }}
          keyExtractor={ (item, index) => index.toString() }
      />
    );
  }
}

export default ImageFeed
