/**
 * drawer file
 *
 *
 * @format
 * @flow
 */

import { Router } from './router';
import HomeScreen from '../View/pages/home';

import { Dimensions } from 'react-native'
import { createAppContainer } from 'react-navigation';
import { createDrawerNavigator } from 'react-navigation-drawer';

const WIDTH = Dimensions.get('window').width;

// Set side menu navigation configuration
const drawerConfig = {
    drawerWidth: WIDTH * 0.75,
    drawerType: 'slide',
}

// Set side menu navigation
const MainNavigator = createDrawerNavigator({

    Account: { screen: HomeScreen },
    'Browse images':  { screen: Router },
    },
    drawerConfig,
);

export const Drawer = createAppContainer(MainNavigator);
