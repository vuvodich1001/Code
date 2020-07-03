#pragma
class ChineseChess {
public:
    virtual void move() = 0;
};

class Tot : public ChineseChess {
public:
    void move();
};

class Phao : public ChineseChess {
public:
    void move();
};

class Xe : public ChineseChess {
public:
    void move();
};

class Ma : public ChineseChess {
public:
    void move();
};

class Tinh : public ChineseChess {
public:
    void move();
};

class Si : public ChineseChess {
public:
    void move();
};

class Tuong : public ChineseChess {
public:
    void move();
};

void menu();
