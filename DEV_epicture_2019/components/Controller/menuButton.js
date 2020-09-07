/**
 * Menu button
 *
 *
 * @format
 * @flow
 */

import React from 'react';
import { Image, TouchableHighlight } from 'react-native'

import styles from '../View/CSS/style'

class MenuButton extends React.Component {

  //Set button for side menu
  render() {
    return (
        <TouchableHighlight style={{height: 70}} onPress={() => {this.props.navigation.toggleDrawer()}}>
            <Image style={styles.menuIcon} source={require('../../ressources/menu.svg')}/>
        </TouchableHighlight>
    );
  }
}

export default MenuButton;
