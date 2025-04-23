#include <iostream>
#include <SFML/Graphics.hpp>

int main() {

    // window setup
    sf::RenderWindow window(sf::VideoMode(800, 600), "Bouncing Ball");
    window.setFramerateLimit(144);

    // screen bounds
    const auto BOUNDS = static_cast<sf::Vector2f>(window.getSize());

    // ball positioning
    bool forwards_x = true;
    bool down_y = true;
    float x = 0;
    float y = 0;

    // ball itself
    constexpr int BALL_RADIUS = 50;
    constexpr float BALL_DIAMETER = BALL_RADIUS*2;
    auto ball = sf::CircleShape(BALL_RADIUS);
    ball.setFillColor(sf::Color::Black);
    ball.setPosition(x, y);

    // game loop
    while (window.isOpen()) {
        // check if ball is OOB
        sf::Vector2f ballPos = ball.getPosition();
        // reverse movement direction if OOB
        if (ballPos.x > BOUNDS.x-BALL_DIAMETER || ballPos.x < 0) {
            forwards_x = !forwards_x;
        }
        if (ballPos.y > BOUNDS.y-BALL_DIAMETER || ballPos.y < 0) {
            down_y = !down_y;
        }

        // move ball
        forwards_x ? x = 3 : x = -3;
        down_y ? y = 3 : y = -3;

        // finally set position
        ball.move(sf::Vector2f(x, y));

        //
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            window.close();
        }

        // draw the window completely white
        window.clear(sf::Color::White);
        window.draw(ball);


        // 'blit' the window
        window.display();
    }

    return 0;
}
