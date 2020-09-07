/*
 * Imgur API implementation
 *
 *
 * @format
 * @flow
 */

import React from 'react';
import { Button, View, ScrollView } from 'react-native';

import { authorize } from 'react-native-app-auth';
import AsyncStorage from '@react-native-community/async-storage';
import Account from '../View/modules/account';
import styles from '../View/CSS/style';
import ImageFeed from './imageFeed'

/**
 * Imgur APi class
 * @class ImgurApi
 * @description Component that contain all the necessary code to call the imgur api and do request with it
 */
export default class ImgurApi extends React.Component {

  //Connect user to Imgur API
  constructor() {
    super();
    this.state = {
      userData: [],
      userDataView: <View>
                      <Button style={styles.loginButton} title='login to imgur' onPress={this.connectUser}/>
                    </View>,
    }
    this.connectUser = this.connectUser.bind(this);
    this.removeCredentials = this.removeCredentials.bind(this);
    this.loadAccountData = this.loadAccountData.bind(this);
    this.fetchData = this.fetchData.bind(this);
  }

  fetchData = async (fetchUrl, apiKey) => {
    await fetch(fetchUrl, {
      method: 'GET',
      headers: {
          'Authorization': 'Client-ID ' + apiKey,
      },
      }).then(response => response.json())
      .then(data => {
          this.setState({ userData: data.data })
        }).catch(error => { console.log("error in fetch : " + error) })
  }

  loadAccountData = async (userName, userToken) => {
    await this.fetchData("https://api.imgur.com/3/account/" + userName, 'a40ee52b57a7011')
    this.setState({userDataView:
      <View>
        <ScrollView style={{flexDirection: 'column'}}>
          <View>
            <Account profilPic={this.state.userData.avatar}
                  userName={userName} 
                  bio={this.state.userData.bio} />
          </View>
          <View>
            <Button style={styles.loginButton} title='log out' onPress={this.removeCredentials}/>
          </View>
          <ImageFeed access='Bearer' fetchUrl='https://api.imgur.com/3/account/me/images' apiKey={ userToken }/>
        </ScrollView>
      </View>
  })
  }

  connectUser = async () => {
    const config = {
      serviceConfiguration: {
        authorizationEndpoint: 'https://api.imgur.com/oauth2/authorize',
        tokenEndpoint: 'https://api.imgur.com/oauth2/token',
      },
      clientId: 'a40ee52b57a7011',
      clientSecret: 'fba6b6b7e7ef622a38633a3dcba02a3cb5f4b89c',
      redirectUrl: 'epicture://auth',
    };

    try {
      const token = await authorize(config)

      await AsyncStorage.setItem('token', token.accessToken)
      console.disableYellowBox = true;
      this.loadAccountData(token.additionalParameters.account_username, token.accessToken);
    } catch (e) {
      console.log("error in connect user : " + e);
    }
  }

  async removeCredentials() {
    try {
      await AsyncStorage.removeItem('token')
      this.setState({userDataView:
        <View>
          <Button style={styles.loginButton} title='login to imgur' onPress={this.connectUser}/>
        </View>
      })
    } catch (e) {
      console.log("error in log out : " + e);
    }
  }

  render() {
    return (
      <View>
        { this.state.userDataView }
      </View>
    );
  }
}
