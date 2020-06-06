#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
   public:
    Component();
    ~Component() = default;

    void accept();
    void add();
    void del();
    virtual bool isComposite() = 0;

    bool isVisible();
};

#endif // COMPONENT_H
