/**
 * Home page
 *
 *
 * @format
 * @flow
 */

import React, { Component }  from 'react';
import { View, Image, Text } from 'react-native';

import styles from '../CSS/style'

class Account extends Component {

    //Get user state from Imgur API
    constructor(props) {
        super(props);
        this.state = {
            profilPic: this.props.profilPic,
            userName: this.props.userName,
            bio: this.props.bio
        }
    }

    render() {
      return (
        //Set user profile with profile picture, username and bio
        <View>
            <View style={styles.profileView}>
                <Image
                style={styles.profilPic}
                source={{ uri: this.state.profilPic }}
                />
            </View>
            <Text style={styles.username}>
                { this.state.userName }
            </Text>
            <View style={{alignItems: 'flex-start', marginBottom: 30}}>
                <Text style={styles.factsResponse}>
                    { this.state.bio }
                </Text>
            </View>
        </View>
      );
    }
  }

export default Account;
