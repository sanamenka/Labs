#include "win.h"
#include <QtWidgets>
Win::Win(QWidget *parent):QWidget(parent) // конструктор
{
 codec = QTextCodec::codecForName("UTF-8");
 this->setWindowTitle(codec->toUnicode("Счетчик")); // название окна

//создание надписей
 label1 = new QLabel(codec->toUnicode("Cчет по 1"),this);
 label2 = new QLabel(codec->toUnicode("Cчет по 5"),this);
//создание счетчиков
 edit1 = new Counter("0",this);
 edit2 = new Counter("0",this);
 edit1->setEnabled(false); // блокирует изменение счетчиков
 edit2->setEnabled(false);
//создаем кнопки
 calcbutton=new QPushButton("+1",this);
 exitbutton=new QPushButton(codec->toUnicode("Выход"),this);

//создание блоков
 QHBoxLayout *layout1 = new QHBoxLayout(); // горизонтальный бокс
 layout1->addWidget(label1);
 layout1->addWidget(label2);
 QHBoxLayout *layout2 = new QHBoxLayout(); // горизонтальный бокс
 layout2->addWidget(edit1);
 layout2->addWidget(edit2);
 QHBoxLayout *layout3 = new QHBoxLayout(); // горизонтальный бокс
 layout3->addWidget(calcbutton);
 layout3->addWidget(exitbutton);
 QVBoxLayout *layout4 = new QVBoxLayout(this); // общий вертикальный бокс
 layout4->addLayout(layout1);
 layout4->addLayout(layout2);
 layout4->addLayout(layout3);

 // связь сигнала нажатия кнопки и слота закрытия окна
 connect(calcbutton,&QPushButton::clicked,
 edit1,&Counter::add_one);

 connect(edit1,&Counter::tick_signal,
 edit2,&Counter::add_one);

 connect(exitbutton,&QPushButton::clicked,
 this,&Win::close);
}
