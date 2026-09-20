#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <cmath>
#include <QPainter>

int main(int argc, char *argv[]) {

    double num;
    int op = 0;

    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("MintCalc");
    window.resize(480, 830);
    window.show();

    QLabel screen;
    screen.setText("0");
    screen.setStyleSheet("font-size: 24px;");
    screen.setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    auto setop = [&](int newOp)
    {
        if (op != 0)
        {
            double current = screen.text().toDouble();

            if (op == 1)
                num += current;
            else if (op == 2)
                num -= current;
            else if (op == 3)
                num *= current;
            else if (op == 4) {
                if (current != 0)
                    num /= current;
                else
                    screen.setText("Cannot Divide By 0");
            }
            else if (op == 5)
                num = std::pow(num, current);

            screen.setText(QString::number(num));
        }
        else
        {
            num = screen.text().toDouble();
        }

        op = newOp;
        screen.setText("0");
    };

    QPushButton zero;
    zero.setText("0");
    zero.setFixedHeight(110);
    QObject::connect(&zero, &QPushButton::clicked, [&]() {
        if (screen.text() == "0") {
            screen.setText("0");
        } else {
            screen.setText(screen.text() + "0");
        }
    });

    QPushButton dot;
    dot.setText(".");
    dot.setFixedSize(110, 110);
    QObject::connect(&dot, &QPushButton::clicked, [&]() {
        if (screen.text() == "0") {
            screen.setText("0.");
        } else {
            screen.setText(screen.text() + ".");
        }
    });

    QPushButton equals;
    equals.setText("=");
    equals.setFixedSize(110, 110);
    QObject::connect(&equals, &QPushButton::clicked, [&]() {
        if (op != 0) {
            if (op == 1) {
                screen.setText(QString::number(num + screen.text().toDouble()));
            } else if (op == 2) {
                screen.setText(QString::number(num - screen.text().toDouble()));
            } else if (op == 3) {
                screen.setText(QString::number(num * screen.text().toDouble()));
            } else if (op == 4) {
                screen.setText(QString::number(num / screen.text().toDouble()));
            }
        }
		num = screen.text().toDouble();
        op = 0;
    });

    QPushButton one;
    one.setText("1");
    one.setFixedSize(110, 110);
    QObject::connect(&one, &QPushButton::clicked, [&]() {
        if (screen.text() == "0") {
            screen.setText("1");
        } else {
            screen.setText(screen.text() + "1");
        }
    });

    QPushButton two;
    two.setText("2");
    two.setFixedSize(110, 110);
    QObject::connect(&two, &QPushButton::clicked, [&]() {
        if (screen.text() == "0") {
            screen.setText("2");
        } else {
            screen.setText(screen.text() + "2");
        }
    });

    QPushButton three;
    three.setText("3");
    three.setFixedSize(110, 110);
    QObject::connect(&three, &QPushButton::clicked, [&]() {
        if (screen.text() == "0") {
            screen.setText("3");
        } else {
            screen.setText(screen.text() + "3");
        }
    });

    QPushButton plus;
    plus.setText("+");
    plus.setFixedSize(110, 110);
    QObject::connect(&plus, &QPushButton::clicked, [&]() {
        setop(1);
    });

    QPushButton four;
    four.setText("4");
    four.setFixedSize(110, 110);
    QObject::connect(&four, &QPushButton::clicked, [&]() {
        if (screen.text() == "0") {
            screen.setText("4");
        } else {
            screen.setText(screen.text() + "4");
        }
    });

    QPushButton five;
    five.setText("5");
    five.setFixedSize(110, 110);
    QObject::connect(&five, &QPushButton::clicked, [&]() {
        if (screen.text() == "0") {
            screen.setText("5");
        } else {
            screen.setText(screen.text() + "5");
        }
    });

    QPushButton six;
    six.setText("6");
    six.setFixedSize(110, 110);
    QObject::connect(&six, &QPushButton::clicked, [&]() {
        if (screen.text() == "0") {
            screen.setText("6");
        } else {
            screen.setText(screen.text() + "6");
        }
    });

    QPushButton minus;
    minus.setText("-");
    minus.setFixedSize(110, 110);
    QObject::connect(&minus, &QPushButton::clicked, [&]() {
        setop(2);
    });

    QPushButton seven;
    seven.setText("7");
    seven.setFixedSize(110, 110);
    QObject::connect(&seven, &QPushButton::clicked, [&]() {
        if (screen.text() == "0") {
            screen.setText("7");
        } else {
            screen.setText(screen.text() + "7");
        }
    });

    QPushButton eight;
    eight.setText("8");
    eight.setFixedSize(110, 110);
    QObject::connect(&eight, &QPushButton::clicked, [&]() {
        if (screen.text() == "0") {
            screen.setText("8");
        } else {
            screen.setText(screen.text() + "8");
        }
    });

    QPushButton nine;
    nine.setText("9");
    nine.setFixedSize(110, 110);
    QObject::connect(&nine, &QPushButton::clicked, [&]() {
        if (screen.text() == "0") {
            screen.setText("9");
        } else {
            screen.setText(screen.text() + "9");
        }
    });

    QPushButton times;
    times.setText("*");
    times.setFixedSize(110, 110);
    QObject::connect(&times, &QPushButton::clicked, [&]() {
        setop(3);
    });

    QPushButton pi;
    pi.setText("π");
    pi.setFixedSize(110, 110);
    QObject::connect(&pi, &QPushButton::clicked, [&]() {
        if (screen.text() == "0") {
            screen.setText("3.141592653");
        }
    });

    QPushButton openp;
    openp.setText("(");
    openp.setFixedSize(110, 110);

    QPushButton closep;
    closep.setText(")");
    closep.setFixedSize(110, 110);

    QPushButton divide;
    divide.setText("/");
    divide.setFixedSize(110, 110);
    QObject::connect(&divide, &QPushButton::clicked, [&]() {
        setop(4);
    });

    QPushButton sqrt;
    sqrt.setText("√");
    sqrt.setFixedSize(110, 110);
    QObject::connect(&sqrt, &QPushButton::clicked, [&]() {
        screen.setText(QString::number(std::sqrt(screen.text().toDouble())));
    });

    QPushButton square;
    square.setText("x²");
    square.setFixedSize(110, 110);
    QObject::connect(&square, &QPushButton::clicked, [&]() {
        screen.setText(QString::number(screen.text().toDouble() * screen.text().toDouble()));
    });

    QPushButton exp;
    exp.setText("x^y");
    exp.setFixedSize(110, 110);
    QObject::connect(&exp, &QPushButton::clicked, [&]() {
        setop(5);
    });

    QPushButton delall;
    delall.setText("AC");
    delall.setFixedSize(110, 110);
    QObject::connect(&delall, &QPushButton::clicked, [&]() {
        screen.setText("0");
    });

    QPushButton calc;
    calc.setText("x");
    calc.setFixedSize(40, 55);

    QPushButton conv;
    conv.setText("⇄");
    conv.setFixedSize(40, 55);

    QGridLayout layout;
    layout.addWidget(&zero, 7, 1, 1, 2);
    layout.addWidget(&dot, 7, 3, 1, 1);
    layout.addWidget(&equals, 7, 4, 1, 1);
    layout.addWidget(&one, 6, 1, 1, 1);
    layout.addWidget(&two, 6, 2, 1, 1);
    layout.addWidget(&three, 6, 3, 1, 1);
    layout.addWidget(&plus, 6, 4, 1, 1);
    layout.addWidget(&four, 5, 1, 1, 1);
    layout.addWidget(&five, 5, 2, 1, 1);
    layout.addWidget(&six, 5, 3, 1, 1);
    layout.addWidget(&minus, 5, 4, 1, 1);
    layout.addWidget(&seven, 4, 1, 1, 1);
    layout.addWidget(&eight, 4, 2, 1, 1);
    layout.addWidget(&nine, 4, 3, 1, 1);
    layout.addWidget(&times, 4, 4, 1, 1);
    layout.addWidget(&pi, 3, 1, 1, 1);
    layout.addWidget(&openp, 3, 2, 1, 1);
    layout.addWidget(&closep, 3, 3, 1, 1);
    layout.addWidget(&divide, 3, 4, 1, 1);
    layout.addWidget(&sqrt, 2, 1, 1, 1);
    layout.addWidget(&square, 2, 2, 1, 1);
    layout.addWidget(&exp, 2, 3, 1, 1);
    layout.addWidget(&delall, 2, 4, 1, 1);
    layout.addWidget(&screen, 0, 1, 2, 4);
    layout.addWidget(&calc, 0, 0, 1, 1);
    layout.addWidget(&conv, 1, 0, 1, 1);
    window.setLayout(&layout);

    QPushButton* defButtons[] = {
        &zero, &one, &two, &three, &four, &five,
        &six, &seven, &eight, &nine, &dot, &pi,
        &openp, &closep, &sqrt, &square, &exp
    };

    QPushButton* opButtons[] = {
        &delall, &divide, &times, &plus, &minus
    };

    for (QPushButton* button : defButtons) {
        button->setStyleSheet(
            "QPushButton {"
            "    background-color: #363636;"
            "    color: white;"
            "    font-size: 24px;"
            "    border-radius: 30px;"
            "}"
            "QPushButton:hover {"
            "    background-color: #4a4a4a;"
            "}"
            "QPushButton:pressed {"
            "    background-color: #5e5e5e;"
            "}"
        );
    }

    for (QPushButton* button : opButtons) {
        button->setStyleSheet(
            "QPushButton {"
            "    background-color: #00afff;"
            "    color: black;"
            "    font-size: 24px;"
            "    border-radius: 30px;"
            "}"
            "QPushButton:hover {"
            "    background-color: #33bfff;"
            "}"
            "QPushButton:pressed {"
            "    background-color: #66cfff;"
            "}"
        );
    }

    equals.setObjectName("equalsButton");
    screen.setObjectName("screenLbl");

    app.setStyleSheet(
        "#equalsButton {"
        "    background-color: #00e5bb;"
        "    color: black;"
        "    font-size: 24px;"
        "    border-radius: 30px;"
        "}"
        "#equalsButton:hover {"
        "    background-color: #33eac7;"
        "}"
        "#equalsButton:pressed {"
        "    background-color: #66efd3;"
        "}"
        "#screenLbl {"
        "    font-size: 32px"
        "}"
    );

    return app.exec();
}