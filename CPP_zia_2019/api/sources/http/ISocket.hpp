#ifndef CPP_ZIA_2019_API_HTTP_ISOCKET_HPP
#define CPP_ZIA_2019_API_HTTP_ISOCKET_HPP

#include "../Types.hpp"

namespace api::http {

    class ISocket {
    public:
        virtual ~ISocket() = default;

        // Return IpV4 of the target of the socket as an unsigned int
        virtual IpV4 getTargetIp() const = 0;

        // Return true if the socket is open
        virtual bool isOpen() const = 0;
        // Call shutdown and close on the socket
        virtual void closeSocket() = 0;

        // Return packets received by the socket. Packet should be separated by "\r\n".
        // If a packet is not ended and contain the separation you should return it.
        // The packet returned should contain "\r\n"
        virtual Buffer recvPacket() = 0;
        // Read a precise size in the socket ignoring "\r\n"
        virtual Buffer recvPacket(unsigned int size) = 0;
        // Send a packet over the socket. Your packet should finish by "\r\n"
        virtual void sendPacket(const Buffer &data) = 0;
    };

}

#endif /* CPP_ZIA_2019_API_HTTP_ISOCKET_HPP */
