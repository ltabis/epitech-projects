/**
 * Router file
 *
 *
 * @format
 * @flow
 */

import FeedScreen from '../View/pages/feed';
import SearchScreen from '../View/pages/search';

import { createAppContainer } from 'react-navigation';
import { createMaterialTopTabNavigator } from 'react-navigation-tabs';

//Creat the navigation between windows
const MainNavigator = createMaterialTopTabNavigator({

    Feed:  { screen: FeedScreen },
    Search:  { screen: SearchScreen },
    },

    {initialRouteName: 'Feed' },
);

export const Router = createAppContainer(MainNavigator);
