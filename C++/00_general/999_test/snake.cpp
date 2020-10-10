
#include <iostream>
#include <windows.h>

using namespace std;

struct position {
    int x,y;
};


class field_cls {
    static const int height;
    static const int width;
    char ** field;
    field_cls(const field_cls &);
    field_cls operator=(const field_cls &);
public:
    field_cls() {
        field = new char*[field_cls::height];
        for(int c = 0; c < field_cls::height; ++c) {
            field[c] = new char[field_cls::width];
        }
    }
    ~field_cls() {
        for(int c = 0; c < field_cls::height; ++c) {
            delete[] field[c];
        }
        delete[] field;
    }

    void print() {
        for(int c = 0; c < height; ++c) {
            for(int r = 0; r < width; ++r) {
                cout << field[c][r];
            }
            cout << endl;
        }
    }

    void clear() {
        for(int c = 0; c < height; ++c) {
            for(int r = 0; r < width; ++r) {
                field[c][r] = ' ';
            }
        }
    }

    int get_width() const {return width;}
    int get_height() const {return height;}


    void draw(int y, int x, char what) {
        //y = (y < 0) ? 0 : (y >= height ? height - 1 : y);
        //x = (x < 0) ? 0 : (x >= width ? width - 1 : x);

        field[y][x] = what;
    }

} field;


class food_cls {
    position pos;
    char symbol;
public:
    food_cls(): symbol('X'), pos() {
        pos.x = pos.y = -1;
    }

    void set_pos(int x, int y) {
        pos.x = x;
        pos.y = y;
    }

    void reposition(const field_cls & field) {
        pos.x = rand() % field.get_width();
        pos.y = rand() % field.get_height();
    }

    int get_x() const {return pos.x;}
    int get_y() const {return pos.y;}
    char get_symbol() const {return symbol;}
} food;

class snake_cls {
    enum {UP, DOWN, LEFT, RIGHT} dir;
    char symbol, head_symbol;
    position pos[100];
    position & head;
    int speed;
    int size;
    bool can_turn;
public:
    snake_cls(int x, int y):
        symbol('#'), head_symbol('@'), pos(),
        speed(1), size(1), dir(RIGHT),
        head(pos[0]), can_turn(true)
    {
        pos[0].x = x;
        pos[0].y = y;
    }

    bool check_food(const food_cls & food) {
        if(food.get_x() == head.x && food.get_y() == head.y) {
            size += 1;
            return true;
        }
        return false;
    }

    void get_input(const field_cls & field) {
        if(GetAsyncKeyState(VK_UP) && dir != DOWN) {
            dir = UP;
        }
        if(GetAsyncKeyState(VK_DOWN) && dir != UP) {
            dir = DOWN;
        }
        if(GetAsyncKeyState(VK_LEFT) && dir != RIGHT) {
            dir = LEFT;
        }
        if(GetAsyncKeyState(VK_RIGHT) && dir != LEFT) {
            dir = RIGHT;
        }
    }

    void move(const field_cls & field) {
        position next = {0, 0};
        switch(dir) {
        case UP:
            next.y = -speed;
            break;
        case DOWN:
            next.y = speed;
            break;
        case LEFT:
            next.x = -speed;
            break;
        case RIGHT:
            next.x = speed;
        }
        for(int c = size - 1; c > 0; --c) {
            pos[c] = pos[c-1];
        }
        head.x += next.x;
        head.y += next.y;

        if(head.x < 0 || head.y < 0 || head.x >= field.get_width() || head.y >= field.get_height()) {
            throw "DEADD!!!!";
        }
    }

    void draw(field_cls & field) {
        for(int c = 0; c < size; ++c) {
            if(c == 0) {
                field.draw(pos[c].y, pos[c].x, head_symbol);
            } else {
                field.draw(pos[c].y, pos[c].x, symbol);
            }
        }
    }

    int get_x() const { return head.x; }
    int get_y() const { return head.y; }
    char get_symbol() const { return symbol; }
} snake(1, 1);


const int field_cls::height = 24;
const int field_cls::width = 79;


int main() {
    field.clear();

    food.set_pos(5, 5);

    while(1) {
        field.clear();

        snake.get_input(field);
        try {
            snake.move(field);
        } catch (const char * er) {
            field.clear();
            cerr << er << endl;
            system("pause");
            return -1;
        }
        snake.draw(field);
        field.draw(food.get_y(), food.get_x(), food.get_symbol());


        if(snake.check_food(food)) {
            food.reposition(field);
        }

        field.print();

        Sleep(1000/30);
        system("cls");
    }

    return 0;
}
