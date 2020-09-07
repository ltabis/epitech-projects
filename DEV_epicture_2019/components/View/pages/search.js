/**
 * Search page
 *
 *
 * @format
 * @flow
 */

import React, { Component }  from 'react';
import { View, Text, TextInput, Image } from 'react-native';

import ImageFeed from '../../Controller/imageFeed'

class SearchScreen extends Component {

  //Get url and gallery state from Imgur API
  constructor() {
    super();
    this.state = {
      text: '',
      fetchUrl: 'https://api.imgur.com/3/gallery/search/top?q=',
      feed: []
    }
  }
  // refresh the research
  updateSearchList = (text) => {
    this.setState({text: text})
    this.setState({feed: <ImageFeed access='Client-ID' fetchUrl={ this.state.fetchUrl + text} apiKey='a40ee52b57a7011'/>})
  }

  //Set the search mod with text input and images
  render() {
    return (
      <View style={{padding: 10, flex: 1, justifyContent: 'center', alignItems: 'center', backgroundColor: '#F5FCFF'}}>
        <TextInput
          style={{height: 40, borderColor: 'black'}}
          placeholder="Search a picture."
          onChangeText={(text) => this.updateSearchList(text)}
          value={this.state.text}
        />
        <Image style={{width: 50, height: 50}} source={require('../../../ressources/search.png')}></Image>
        <Text style={{padding: 10, fontSize: 42}}>
          {this.state.text.split(' ').map((word) => word).join(' ')}
        </Text>
        { this.state.feed }
      </View>
    );
  }
}

export default SearchScreen;
