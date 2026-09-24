#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <cmath>
#include <QPainter>
#include <QTabWidget>

int main(int argc, char *argv[]) {

    double num;
    int op = 0;
    bool issto = false;
    bool isvar = false;
    double va = 0;
    double vb = 0;
    double vc = 0;
    double vd = 0;
    double ve = 0;
    double vf = 0;


    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("MintCalc");
    window.setMaximumSize(480, 1000);
    window.resize(480, 1000);
    window.show();

    QTabWidget tabs;

    QWidget calcTab;
    QWidget memTab;

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

    QLabel albl;
    albl.setText("A = 0");
    QLabel blbl;
    blbl.setText("B = 0");
    QLabel clbl;
    clbl.setText("C = 0");
    QLabel dlbl;
    dlbl.setText("D = 0");
    QLabel elbl;
    elbl.setText("E = 0");
    QLabel flbl;
    flbl.setText("F = 0");
    albl.setFixedHeight(50);
    blbl.setFixedHeight(50);
    clbl.setFixedHeight(50);
    dlbl.setFixedHeight(50);
    elbl.setFixedHeight(50);
    flbl.setFixedHeight(50);

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

    QPushButton five;
    five.setText("5");
    five.setFixedSize(110, 110);

    QPushButton six;
    six.setText("6");
    six.setFixedSize(110, 110);

    QPushButton minus;
    minus.setText("-");
    minus.setFixedSize(110, 110);
    QObject::connect(&minus, &QPushButton::clicked, [&]() {
        setop(2);
    });

    QPushButton seven;
    seven.setText("7");
    seven.setFixedSize(110, 110);

    QPushButton eight;
    eight.setText("8");
    eight.setFixedSize(110, 110);

    QPushButton nine;
    nine.setText("9");
    nine.setFixedSize(110, 110);

    QObject::connect(&seven, &QPushButton::clicked, [&]() {

        if (issto) {
            va = screen.text().toDouble();
            albl.setText("A = " + screen.text());

            seven.setText("7");
            eight.setText("8");
            nine.setText("9");
            four.setText("4");
            five.setText("5");
            six.setText("6");

            issto = false;
            isvar = false;

            return;
        }

        if (isvar) {
            screen.setText(QString::number(va));
            return;
        }

        if (screen.text() == "0")
            screen.setText("7");
        else
            screen.setText(screen.text() + "7");
    });

    QObject::connect(&eight, &QPushButton::clicked, [&]() {

        if (issto) {
            vb = screen.text().toDouble();
            blbl.setText("B = " + screen.text());

            seven.setText("7");
            eight.setText("8");
            nine.setText("9");
            four.setText("4");
            five.setText("5");
            six.setText("6");

            issto = false;
            isvar = false;

            return;
        }

        if (isvar) {
            screen.setText(QString::number(vb));
            return;
        }

        if (screen.text() == "0")
            screen.setText("8");
        else
            screen.setText(screen.text() + "8");
    });

    QObject::connect(&nine, &QPushButton::clicked, [&]() {

        if (issto) {
            vc = screen.text().toDouble();
            clbl.setText("C = " + screen.text());

            seven.setText("7");
            eight.setText("8");
            nine.setText("9");
            four.setText("4");
            five.setText("5");
            six.setText("6");

            issto = false;
            isvar = false;

            return;
        }

        if (isvar) {
            screen.setText(QString::number(vc));
            return;
        }

        if (screen.text() == "0")
            screen.setText("9");
        else
            screen.setText(screen.text() + "9");
    });


    QObject::connect(&four, &QPushButton::clicked, [&]() {

        if (issto) {
            vd = screen.text().toDouble();
            dlbl.setText("D = " + screen.text());

            seven.setText("7");
            eight.setText("8");
            nine.setText("9");
            four.setText("4");
            five.setText("5");
            six.setText("6");

            issto = false;
            isvar = false;

            return;
        }

        if (isvar) {
            screen.setText(QString::number(vd));
            return;
        }

        if (screen.text() == "0")
            screen.setText("4");
        else
            screen.setText(screen.text() + "4");
    });

    QObject::connect(&five, &QPushButton::clicked, [&]() {

        if (issto) {
            ve = screen.text().toDouble();
            elbl.setText("E = " + screen.text());

            seven.setText("7");
            eight.setText("8");
            nine.setText("9");
            four.setText("4");
            five.setText("5");
            six.setText("6");

            issto = false;
            isvar = false;

            return;
        }

        if (isvar) {
            screen.setText(QString::number(ve));
            return;
        }

        if (screen.text() == "0")
            screen.setText("5");
        else
            screen.setText(screen.text() + "5");
    });


    QObject::connect(&six, &QPushButton::clicked, [&]() {

        if (issto) {
            vf = screen.text().toDouble();
            flbl.setText("F = " + screen.text());

            seven.setText("7");
            eight.setText("8");
            nine.setText("9");
            four.setText("4");
            five.setText("5");
            six.setText("6");

            issto = false;
            isvar = false;

            return;
        }

        if (isvar) {
            screen.setText(QString::number(vf));
            return;
        }

        if (screen.text() == "0")
            screen.setText("6");
        else
            screen.setText(screen.text() + "6");
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
        } else {
            screen.setText(QString::number(screen.text().toDouble() * std::numbers::pi));
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

    QPushButton log10;
    log10.setText("log(x)");
    log10.setFixedSize(110, 110);
    QObject::connect(&log10, &QPushButton::clicked, [&]() {
        screen.setText(QString::number(std::log10(screen.text().toDouble())));
    });

    QPushButton ln;
    ln.setText("ln(x)");
    ln.setFixedSize(110, 110);
    QObject::connect(&ln, &QPushButton::clicked, [&]() {
        screen.setText(QString::number(std::log(screen.text().toDouble())));
    });

    QPushButton sto;
    sto.setText("->");
    sto.setFixedSize(110, 110);
    QObject::connect(&sto, &QPushButton::clicked, [&]() {
        if (issto == false) {
            seven.setText("A");
            eight.setText("B");
            nine.setText("C");
            four.setText("D");
            five.setText("E");
            six.setText("F");
            issto = !issto;
        } else {
            seven.setText("7");
            eight.setText("8");
            nine.setText("9");
            four.setText("4");
            five.setText("5");
            six.setText("6");
            issto = !issto;
        }
        isvar = false;
    });

    QPushButton var;
    var.setText("var");
    var.setFixedSize(110, 110);
    QObject::connect(&var, &QPushButton::clicked, [&]() {
        if (isvar == false) {
            seven.setText("A");
            eight.setText("B");
            nine.setText("C");
            four.setText("D");
            five.setText("E");
            six.setText("F");
            isvar = !isvar;
        } else {
            seven.setText("7");
            eight.setText("8");
            nine.setText("9");
            four.setText("4");
            five.setText("5");
            six.setText("6");
            isvar = !isvar;
        }
        issto = false;
    });

    QGridLayout calcLayout(&calcTab);
    QVBoxLayout memLayout(&memTab);
    memLayout.setSpacing(2);
    memLayout.setContentsMargins(5, 5, 5, 5);
    calcLayout.addWidget(&zero, 7, 1, 1, 2);
    calcLayout.addWidget(&dot, 7, 3, 1, 1);
    calcLayout.addWidget(&equals, 7, 4, 1, 1);
    calcLayout.addWidget(&one, 6, 1, 1, 1);
    calcLayout.addWidget(&two, 6, 2, 1, 1);
    calcLayout.addWidget(&three, 6, 3, 1, 1);
    calcLayout.addWidget(&plus, 6, 4, 1, 1);
    calcLayout.addWidget(&four, 5, 1, 1, 1);
    calcLayout.addWidget(&five, 5, 2, 1, 1);
    calcLayout.addWidget(&six, 5, 3, 1, 1);
    calcLayout.addWidget(&minus, 5, 4, 1, 1);
    calcLayout.addWidget(&seven, 4, 1, 1, 1);
    calcLayout.addWidget(&eight, 4, 2, 1, 1);
    calcLayout.addWidget(&nine, 4, 3, 1, 1);
    calcLayout.addWidget(&times, 4, 4, 1, 1);
    calcLayout.addWidget(&pi, 3, 1, 1, 1);
    calcLayout.addWidget(&openp, 3, 2, 1, 1);
    calcLayout.addWidget(&closep, 3, 3, 1, 1);
    calcLayout.addWidget(&divide, 3, 4, 1, 1);
    calcLayout.addWidget(&sqrt, 2, 1, 1, 1);
    calcLayout.addWidget(&square, 2, 2, 1, 1);
    calcLayout.addWidget(&exp, 2, 3, 1, 1);
    calcLayout.addWidget(&delall, 2, 4, 1, 1);
    calcLayout.addWidget(&log10, 1, 1, 1, 1);
    calcLayout.addWidget(&ln, 1, 2, 1, 1);
    calcLayout.addWidget(&sto, 1, 3, 1, 1);
    calcLayout.addWidget(&var, 1, 4, 1, 1);
    calcLayout.addWidget(&screen, 0, 1, 1, 4);
    memLayout.addWidget(&albl);
    memLayout.addWidget(&blbl);
    memLayout.addWidget(&clbl);
    memLayout.addWidget(&dlbl);
    memLayout.addWidget(&elbl);
    memLayout.addWidget(&flbl);
    memLayout.addStretch();
    tabs.addTab(&calcTab, "Calculator");
    tabs.addTab(&memTab, "Memory");


    QVBoxLayout mainLayout(&window);
    mainLayout.addWidget(&tabs);

    QPushButton* defButtons[] = {
        &zero, &one, &two, &three, &four, &five,
        &six, &seven, &eight, &nine, &dot, &pi,
        &openp, &closep, &sqrt, &square, &exp,
        &log10, &ln, &sto, &var
    };

    QPushButton* opButtons[] = {
        &delall, &divide, &times, &plus, &minus
    };

    QLabel* memLbl[] = {
        &albl, &blbl, &clbl, &dlbl, &elbl, &flbl
    };

    for (QLabel* label : memLbl) {
        label->setStyleSheet(
            "QLabel {"
            "    font-size: 32px;"
            "}"
        );
    }

    for (QPushButton* button : defButtons) {
        button->setStyleSheet(
            "QPushButton {"
            "    background-color: #363636;"
            "    color: white;"
            "    font-size: 24px;"
            "    border-radius: 55px;"
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
            "    border-radius: 55px;"
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
        "    border-radius: 55px;"
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