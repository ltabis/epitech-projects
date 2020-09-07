/**
 * Creating a video view
 *
 *
 * @format
 * @flow
 */

import React from 'react';
import { View, Text } from 'react-native';
import Video from 'react-native-video'

import styles from '../CSS/style'

class VideoBlock extends React.Component {

  //Get images state from Imgur API
  constructor(props) {
    super(props);
    this.state = {
        title: this.props.title,
        link: this.props.link,
        id: this.props.id,
      };
  }

  //Get and set imgur videos with title
  render() {
    return (
        <View style={ styles.boxView }>
            <Text style={ styles.imageTitle }>{ this.state.title }</Text>
            <Video style={ styles.imageView } key={ this.state.id } source={{ uri: this.state.link }} />
        </View>
  );
}
}

export default VideoBlock
