/**
 *  @file     src/net/BoostService.hpp
 *  @author   amillot on the 2020-02-09
 *  @date     2020-02-09
 * 
 *  project: zia
 * 
 */


#pragma once

#include <boost/asio.hpp>

namespace zia::net {

    /** 
     * @brief A class which implements a custom service used by every boost connection.
     * This class acts as a singleton, in order to manage properly the ioservice of boost.
     * Made with the Boost library, version 1.71.
     */
    class BoostService {
    public:
        /** 
         * @brief BoostService copy constructor, which is deleted.
         * @param other : The other service to copy.
         */
        BoostService(const BoostService &other) = delete;
        
        /** 
         * @brief operator= default overloading, which is deleted.
         * @return BoostService &
         * @param service : The other service to copy.
         */
        BoostService &operator=(const BoostService &service) = delete;
        
        /** 
         * @brief BoostService destructor, which stops the ioservice for everyone.
         */
        ~BoostService() { stop(); }

        /** 
         * @brief Start the service. Be careful, it will affects all your boost connections.
         * @return void
         */
        inline void run(void)
        {
            if (!_isRunning)
            {
                _ioService.run();
                _isRunning = true;
            }
        }

        /** 
         * @brief Stop the service. Be careful, it will affects all your boost connections.
         * @return void
         */
        inline void stop(void)
        {
            if (_isRunning)
            {
                _ioService.stop();
                _isRunning = false;
            }
        }


        /*  <-------------------- Getters -------------------->  */

        /** 
         * @brief Return the unique BoostService of the process.
         * @return BoostService &
         */
        static inline BoostService &get()
        {
            static BoostService service;
             
            return service;
        }


        /** 
         * @brief ioService
         * @return boost::asio::io_service &
         */
        inline boost::asio::io_service &ioService()
        {
            return _ioService;
        }


    private:
        /** 
         * @brief BoostService default constructor, which is private to implement the class as a singleton.
         */
        BoostService() : _ioService(), _isRunning(false) {  }

    private:
        boost::asio::io_service _ioService;
        bool _isRunning;
    };

}