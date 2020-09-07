import { StyleSheet } from 'react-native';

const styles = StyleSheet.create({

  centerStyle: {
    flex : 1,
    alignItems: 'center',
    justifyContent: 'center',
  },

  //Style of the profile picture in profile page
  profilPic: {
    width: 200,
    height: 200,
    borderRadius: 100,
    borderWidth: 2,
    borderColor: '#ffbb33',
  },

  //Style of the profile window
  profileView : {
    flex: 1,
    flexDirection: 'row',
    justifyContent: 'center',
  },

  //Style of the login button in profile page
  loginButton: {
   marginTop: 30,
   backgroundColor: '#ffbb33',
  },

  //Style of the username in profile page
  username: {
    fontWeight: 'bold',
    fontSize: 45,
    marginTop: 20,
    marginBottom: 20,
    color: "#000000",
  },

  //Style of the user informations title
  facts: {
    fontSize: 19,
    fontWeight: 'bold',
    marginBottom: 20,
    color: '#000000',
  },

  //Style of the user informations response
  factsResponse: {
    fontSize: 15,
    marginLeft: 10,
    color: '#000000',
  },

  //Style of informations background
  factsBackground: {
    backgroundColor: '#DCDCDC',
  },

  //Style of image window in feed
  imageView: {
    justifyContent: 'center',
    alignItems: 'center',
    width: 391.5,
    height: 350,
    marginRight: '0.5%',
    borderRadius: 10,
    borderWidth: 3,
    borderColor: '#ffbb33',
  },

  //Style of the image title in feed
  imageTitle: {
    textAlign: 'center',
    fontSize: 20,
    backgroundColor: '#ffbb33',
    textShadowColor: 'rgba(0, 0, 0, 0.75)',
    textShadowOffset: {width: -1, height: 1},
    textShadowRadius: 10,
  },

  //Style of box in feed
  boxView: {
    flex: 1,
    backgroundColor: '#ffbb33',
    margin: 10,
    borderRadius: 10,
  },

  //Style of the menu icon
  menuIcon: {
    zIndex: 9,
    top: 20,
    left: 20,
    width: 40,
    height: 40,
  },

  //Style of the feed background
  feed: {
    backgroundColor: '#293133'
  },

  //Style of footer icon on image in Feed
  footerIcon: {
    width: 30,
    height: 30,
    marginTop: 10,
    marginBottom: 20,
  },
})

export default styles
