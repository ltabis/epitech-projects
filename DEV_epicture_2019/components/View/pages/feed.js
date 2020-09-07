/**
 * Feed page with main gallery images
 *
 *
 * @format
 * @flow
 */

import React from 'react';
import { View } from 'react-native';

import styles from '../CSS/style'
import ImageFeed from '../../Controller/imageFeed'

class FeedScreen extends React.Component {

  //set the feed with images
  render() {
    return (
      <View style={styles.feed}>
        <ImageFeed access='Client-ID' fetchUrl='https://api.imgur.com/3/gallery/hot/viral/0.json' apiKey='a40ee52b57a7011'/>
      </View>
    );
  }
}

export default FeedScreen
