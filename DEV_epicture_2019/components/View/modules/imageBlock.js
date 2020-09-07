/**
 * Creating an image view
 *
 *
 * @format
 * @flow
 */

import React from 'react';
import { View, Image, Text } from 'react-native';

import styles from '../CSS/style'

class ImageBlock extends React.Component {

    //Get images state from Imgur API
    constructor(props) {
        super(props);
        this.state = {
            title: this.props.title,
            link: this.props.link,
            id: this.props.id,
          };
    }
    //Get and set imgur images with title and footer (like, view and save)
    render() {
        return (
            <View style={ styles.boxView }>
                <Text style={ styles.imageTitle }>{ this.state.title }</Text>
                <Image style={ styles.imageView } key={ this.state.id } source={{ uri: this.state.link }} />
                <View style={{flex: 1, justifyContent: 'space-around', alignItems: 'center', flexDirection: 'row'}}>
                  <Image style={styles.footerIcon} source={require('../../../ressources/eye.png')}></Image>
                  <Text>14,896</Text>
                  <Image style={styles.footerIcon} source={require('../../../ressources/heart.png')}></Image>
                  <Text>3,498</Text>
                  <Image style={styles.footerIcon} source={require('../../../ressources/notsave.png')}></Image>
                </View>
            </View>
      );
    }
  }

export default ImageBlock
