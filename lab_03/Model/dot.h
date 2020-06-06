#ifndef DOT_H
#define DOT_H


class Dot {
   public:
    Dot();
    ~Dot() = default;

    void move();
    void rotate();
    void scale();
    Dot get();
    void set();

   private:
    int xPosition, yPosition, zPosition;
};

#endif // DOT_H
