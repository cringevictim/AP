#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unistd.h>

#define XMIN 0
#define XMAX 2
#define ACCURACY 1000 //Точність прорисовки

using namespace std;
using namespace sf;

vector <pair <float, float>> curve_coord(float xl, float xr, float yb, float yt) //Створення масиву точок, котрі будуть складати графік
{                                                                           // xl, xr, yb, yt - границі вікна
    vector <pair <float, float>> coord; //Масив точок, де для кожної зберігається х та у
    if ((xl <= XMAX) && (xr >= XMIN)) { //Создаём массив только если график лежит в пределах окна
        float x, y;
        for (y = yb; y <= yt; y += (yt - yb) / ACCURACY) {
            x = exp(2 * y);
            coord.push_back({ x, y });
        }
    }
    return coord;
}

//Отрисовка графика
void draw_graph(RenderWindow& a_window, float xl, float xr, float yb, float yt, vector <pair <float, float> >& a_curve, VertexArray& graph)
{
    graph.clear();
    int i;
    for (i = 0; i < a_curve.size(); i++) {
        //Высчитываем координаты точки в пикселях, учитывая её числовые координаты и числовые границы окна
        float xpic = (a_curve[i].first - xl) / (xr - xl) * a_window.getSize().x;
        float ypic = (yt - a_curve[i].second) / (yt - yb) * a_window.getSize().y;
        graph.append(Vertex(Vector2f(xpic, ypic), Color::Blue)); //Отрисовуем точку
    }
}

void draw_x_axis(RenderWindow& a_window, float xl, float xr, float yb, float yt, Font& a_font, VertexArray& axis) //Отрисовка оси ОХ
{
    float ypic, markb, markt; int i;
    Text name("X", a_font);
    name.setFillColor(Color::Green);
    if (yb >= 0) { //Если ось ниже нижней границы окна отображаем её на нижней границе
        ypic = markb = a_window.getSize().y - 1;
        markt = markb - 7;
        name.setPosition(a_window.getSize().x - 15, ypic - 45);
    }
    else if (yt <= 0) {//Если ось выше верхей границы окна отображаем её на верхней границе
        ypic = markt = 1;
        markb = markt + 7;
        name.setPosition(a_window.getSize().x - 15, ypic);
    }
    else { //Иначе отображаем ось в нужном месте относительно числовых границ окна
        ypic = (yt) / (yt - yb) * a_window.getSize().y;
        markb = ypic + 10;
        markt = ypic - 10;
        name.setPosition(a_window.getSize().x - 15, ypic);
    }
    a_window.draw(name);
    axis.clear();
    //Отрисовка самой оси и стрелок на её конце
    axis.append(Vertex(Vector2f(a_window.getSize().x, ypic), Color::Green));
    axis.append(Vertex(Vector2f(a_window.getSize().x - 10, ypic - 10), Color::Green));
    axis.append(Vertex(Vector2f(a_window.getSize().x, ypic), Color::Green));
    axis.append(Vertex(Vector2f(a_window.getSize().x - 10, ypic + 10), Color::Green));
    axis.append(Vertex(Vector2f(0, ypic), Color::Green));
    axis.append(Vertex(Vector2f(a_window.getSize().x, ypic), Color::Green));
    for (i = trunc(xl); i <= trunc(xr); i++) { //Проставляем все целые числа и пометки на оси, которые есть в поле зрения
        float mark = (i - xl) / (xr - xl) * a_window.getSize().x;
        //Отрисовка пометки
        axis.append(Vertex(Vector2f(mark, markt), Color::Green));
        axis.append(Vertex(Vector2f(mark, markb), Color::Green));
        Text txt(to_string(i), a_font, 20);
        if (yb >= 0) //Отрисовка текста в зависимости от того, где отрисована ось
            txt.setPosition(mark - 7, markt - 23);
        else
            txt.setPosition(mark - 7, markb - 5);
        txt.setFillColor(Color::Green);
        a_window.draw(txt);
    }
}

void draw_y_axis(RenderWindow& a_window, float xl, float xr, float yb, float yt, Font& a_font, VertexArray& axis) //Отрисовка оси ОХ
{
    float xpic, markl, markr; int i;
    Text name("Y", a_font);
    name.setFillColor(Color::Red);
    if (xl >= 0) { //Если ось левее левой границы окна отображаем её на левойгранице
        xpic = markl = 1;
        markr = markl + 7;
        name.setPosition(xpic + 15, -5);
    }
    else if (xr <= 0) { //Если ось правее правой границы окна отображаем её на правой границе
        xpic = markr = a_window.getSize().x - 1;
        markl = markr - 7;
        name.setPosition(xpic - 25, -5);
    }
    else { //Иначе отображаем ось в нужном месте относительно числовых границ окна
        xpic = (0 - xl) / (xr - xl) * a_window.getSize().x;
        markl = xpic - 10;
        markr = xpic + 10;
        name.setPosition(xpic - 25, -5);
    }
    a_window.draw(name);
    axis.clear();
    //Отрисовка самой оси и стрелок на её конце
    axis.append(Vertex(Vector2f(xpic, 0), Color::Red));
    axis.append(Vertex(Vector2f(xpic - 10, 10), Color::Red));
    axis.append(Vertex(Vector2f(xpic, 0), Color::Red));
    axis.append(Vertex(Vector2f(xpic + 10, 10), Color::Red));
    axis.append(Vertex(Vector2f(xpic, 0), Color::Red));
    axis.append(Vertex(Vector2f(xpic, a_window.getSize().y), Color::Red));
    for (i = trunc(yb); i <= trunc(yt); i++) { //Проставляем все целые числа и пометки на оси, которые есть в поле зрения
        float mark = (yt - i) / (yt - yb) * a_window.getSize().y;
        //Отрисовка пометки
        axis.append(Vertex(Vector2f(markl, mark), Color::Red));
        axis.append(Vertex(Vector2f(markr, mark), Color::Red));
        Text txt(to_string(i), a_font, 20);
        if (xl >= 0) //Отрисовка текста в зависимости от того, где отрисована ось
            txt.setPosition(markr + 2, mark - 16);
        else
            txt.setPosition(markl - 15, mark - 16);
        txt.setFillColor(Color::Red);
        a_window.draw(txt);
    }
}

int main()
{
    float x_left, x_right, y_bottom = -4, y_top = 4, zoom = 1;
    Font font;
    font.loadFromFile("my_font.otf");
    cout << "Use LEFT, RIGHT, UP and DOWN to move and Mouse Wheel to scale." << endl << endl;
    cout << "Please, enter left and right coordinate X: ";
    cin >> x_left >> x_right; //Ввод границ по оси ОХ
    if ((x_left > 0) && (x_left < 2)) { //Скалирование границ по оси OY относительно границ по ОХ
        y_bottom = -4 * M_PI;
        y_top = 4 * M_PI;
    }
    else if ((x_right < 2) && (x_right > 0)) {
        y_bottom = -2 * M_PI;
        y_top = 2 * M_PI;
    }

    RenderWindow window(VideoMode(600, 600), "Graph");

    while (window.isOpen())
    {
        VertexArray curve(LineStrip, 0); //Массив точек, которые будут составлять график. LineStrip означает что каждая
        //последующая точка будет соединена с предыдущей
        VertexArray y_axis(Lines, 0); //Массивы точек, которые будут составлять оси. Lines означает что эти точки будут соединены
        VertexArray x_axis(Lines, 0); //попарно, первая со второй, третья с четвертой и тд, составляя раздельные линии

        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case Event::Closed: //При закрытии окна
                    window.close();
                case Event::MouseWheelMoved: //Прокрутка колеса мыши
                    if ((event.mouseWheel.delta == 1) && (zoom < 10)) { //Колесо мыши прокрутилось вверх и график еще не приближен слишком сильно
                        zoom *= 1.2;
                        x_left++;
                        x_right--;
                        y_bottom++;
                        y_top--;
                    }
                    else if ((event.mouseWheel.delta == -1) && (zoom > 0.1)) { //Колесо мыши прокрутилось вниз и график еще не отдален слишком сильно
                        zoom *= 0.7;
                        x_left--;
                        x_right++;
                        y_bottom--;
                        y_top++;
                    }
            }
        }


        float moving_speed = 0.1;
        if (Keyboard::isKeyPressed(Keyboard::Down)) { //Движение графика вниз
            y_bottom -= moving_speed;
            y_top -= moving_speed;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) { //Движение графика вверх
            y_bottom += moving_speed;
            y_top += moving_speed;
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) { //Движение графика влево
            x_left -= moving_speed;
            x_right -= moving_speed;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) { //Движение графика вправо
            x_left += moving_speed;
            x_right += moving_speed;
        }
        sleep(0.3);

        window.clear();
        vector <pair <float, float>> c = curve_coord(x_left, x_right, y_bottom, y_top); //Нахождение точек графика
        //Отрисовка
        draw_graph(window, x_left, x_right, y_bottom, y_top, c, curve);
        draw_y_axis(window, x_left, x_right, y_bottom, y_top, font, y_axis);
        draw_x_axis(window, x_left, x_right, y_bottom, y_top, font, x_axis);
        window.draw(curve);
        window.draw(y_axis);
        window.draw(x_axis);
        window.display();
    }
    return 0;
}
