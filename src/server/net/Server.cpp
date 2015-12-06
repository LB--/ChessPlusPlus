#include "Server.hpp"

#include "Player.hpp"

#include <stdexcept>
#include <vector>

#include <boost/thread.hpp>

#include <SFML/Network.hpp>

namespace chesspp { namespace server
{
    namespace net
    {
        struct Server::Impl final
        {
			std::uint16_t port;
            sf::TcpListener listener;
			std::vector<Player> players;

            Impl(std::uint16_t port)
            : port{port}
            {
            }
        };
        Server::Server(std::uint16_t port)
        : impl{std::make_unique<Impl>(port)}
        {
        }
        Server::~Server() = default;

        void Server::start()
        {
            auto status = impl->listener.listen(impl->port);
			if(status != sf::Socket::Done)
			{
				throw std::runtime_error{"Error starting server on port"}; //TODO
			}
			while(true) //TODO
			{
				impl->players.emplace_back(std::ref(impl->listener));
			}
        }
        void Server::stop()
        {
            impl->listener.close();
        }
    }
}}
