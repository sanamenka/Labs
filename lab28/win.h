#ifndef win_h
#define win_h
#include <QtWidgets>
class Counter:public QLineEdit // создаем класс редактируемой строки
{
    Q_OBJECT // макрос для компиляции слотов и сигналов

public:

Counter(const QString & contents, QWidget *parent=0):QLineEdit(contents,parent){} //конструктор

signals:
    void tick_signal(); // новый сигнал
public slots:
    void add_one() // новый слот
    {
        QString str=text(); // запись из текстового поля
        int r=str.toInt(); // переводим в int
        r++;
        if (r!=0 && r%5 ==0) emit tick_signal(); //если значение кратно 5 вызываем tick_signal
        str.setNum(r);
        setText(str); // записываем новый текст в поле
    }
};

class Win: public QWidget // класс окна
{
    Q_OBJECT
protected:
    QTextCodec *codec;
    QLabel *label1,*label2;
    Counter *edit1,*edit2;
    QPushButton *calcbutton;
    QPushButton *exitbutton;
public:
    Win(QWidget *parent = 0);// конструктор
};
#endif
