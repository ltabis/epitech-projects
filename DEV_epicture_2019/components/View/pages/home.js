/**
 * Home page
 *
 *
 * @format
 * @flow
 */

import React, { Component }  from 'react';
import { View } from 'react-native'
import ImgurApi from '../../Controller/api';
import MenuButton from '../../Controller/menuButton'

class HomeScreen extends Component {

    //main page, connection to Imgur
    render() {
      return (
        <View>
          <MenuButton navigation={this.props.navigation}/>
          <ImgurApi/>
        </View>
      );
    }
  }

export default HomeScreen;
