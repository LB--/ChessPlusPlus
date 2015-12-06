#include "Player.hpp"

#include <stdexcept>

#include <boost/optional.hpp>
#include <boost/thread.hpp>

#include <SFML/Network.hpp>

namespace chesspp { namespace server
{
    namespace net
    {
        struct Player::Impl final
        {
            sf::TcpSocket client;
			boost::optional<boost::thread> thread;

			Impl() = default;
			Impl(sf::TcpListener &listener)
			{
				auto status = listener.accept(client);
				if(status != sf::Socket::Done)
				{
					throw std::runtime_error{"Error accepting client"}; //TODO
				}
			}
			void handle()
			{
				//TODO
			}
        };
		Player::Player(sf::TcpListener &listener)
		: impl{std::make_unique<Impl>(listener)}
		{
			impl->thread.emplace(Impl::handle, &*impl);
		}
		Player::Player(Player &&from) noexcept
		: impl{std::make_unique<Impl>()}
		{
			std::swap(impl, from.impl);
		}
		Player &Player::operator=(Player &&from) noexcept
		{
			std::swap(impl, from.impl);
			return *this;
		}
		Player::~Player() = default;
		bool Player::connected() const noexcept
		{
			return impl->thread != boost::none && impl->thread->joinable();
		}
    }
}}
