#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <cmath>
#include <QPainter>
#include <QTabWidget>
#include <QDebug>
#include <QComboBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include <iostream>
#include <cstdlib>
#include <ctime>

int factorial(double n) {
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        ans = ans * i;
    }
    return ans;
}

int main(int argc, char *argv[]) {
    std::srand(std::time(nullptr));

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
    QString c1i = "Decimal";
    QString c2i = "Decimal";
    QString c3i = "Meters";
    QString c4i = "Meters";
    QString c5i = "Kilograms";
    QString c6i = "Kilograms";

    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("MintCalc");
    window.setMaximumSize(480, 1000);
    window.resize(480, 1000);
    window.show();

    QTabWidget tabs;

    QWidget calcTab;
    QWidget memTab;
    QWidget convTab;
    QWidget probTab;

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

    QPushButton recip;
    recip.setText("1/x");
    recip.setFixedSize(110, 110);
    QObject::connect(&recip, &QPushButton::clicked, [&]() {
        screen.setText(QString::number(1.0 / screen.text().toDouble()));
    });

    QPushButton fact;
    fact.setText("!");
    fact.setFixedSize(110, 110);
    QObject::connect(&fact, &QPushButton::clicked, [&]() {
        screen.setText(QString::number(factorial(screen.text().toDouble())));
    });

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

    QLineEdit conva;
    conva.setPlaceholderText("Number:");

    QLabel ares;
    ares.setText("");

    QComboBox c1;
    c1.addItem("Decimal");
    c1.addItem("Binary");
    c1.addItem("Hexadecimal");
    QObject::connect(&c1, &QComboBox::currentIndexChanged, [&](int index) {
        c1i = c1.itemText(index);
    });

    QComboBox c2;
    c2.addItem("Decimal");
    c2.addItem("Binary");
    c2.addItem("Hexadecimal");
    QObject::connect(&c2, &QComboBox::currentIndexChanged, [&](int index) {
        c2i = c2.itemText(index);
    });

    QPushButton convert1;
    convert1.setText("Convert");
    QObject::connect(&convert1, &QPushButton::clicked, [&]() {
        if (c1i == c2i) {
            ares.setText(conva.text());
        } else if (c1i == "Decimal" && c2i == "Binary") {
            ares.setText(QString::number(conva.text().toInt(), 2));
        } else if (c1i == "Decimal" && c2i == "Hexadecimal") {
            ares.setText(QString::number(conva.text().toInt(), 16));
        } else if (c1i == "Binary" && c2i == "Decimal") {
            ares.setText(QString::number(conva.text().toInt(nullptr, 2)));
        } else if (c1i == "Binary" && c2i == "Hexadecimal") {
            ares.setText(QString::number(conva.text().toInt(nullptr, 2), 16));
        } else if (c1i == "Hexadecimal" && c2i == "Decimal") {
            ares.setText(QString::number(conva.text().toInt(nullptr, 16)));
        } else if (c1i == "Hexadecimal" && c2i == "Binary") {
            ares.setText(QString::number(conva.text().toInt(nullptr, 16), 2));
        }
    });

    QLineEdit convb;
    convb.setPlaceholderText("Number:");

    QLabel bres;
    bres.setText("");

    QComboBox c3;
    c3.addItem("Meters");
    c3.addItem("Centimeters");
    c3.addItem("Kilometers");
    c3.addItem("Feet");
    c3.addItem("Inches");
    QObject::connect(&c3, &QComboBox::currentIndexChanged, [&](int index) {
        c3i = c3.itemText(index);
    });

    QComboBox c4;
    c4.addItem("Meters");
    c4.addItem("Centimeters");
    c4.addItem("Kilometers");
    c4.addItem("Feet");
    c4.addItem("Inches");
    QObject::connect(&c4, &QComboBox::currentIndexChanged, [&](int index) {
        c4i = c4.itemText(index);
    });

    QPushButton convert2;
    convert2.setText("Convert");
    QObject::connect(&convert2, &QPushButton::clicked, [&]() {
        if (c3i == c4i) {
            bres.setText(convb.text());
        } else if (c3i == "Meters" && c4i == "Feet") {
            bres.setText(QString::number(convb.text().toDouble() * 3.28084));
        } else if (c3i == "Meters" && c4i == "Inches") {
            bres.setText(QString::number(convb.text().toDouble() * 39.3701));
        } else if (c3i == "Meters" && c4i == "Centimeters") {
            bres.setText(QString::number(convb.text().toDouble() * 100));
        } else if (c3i == "Meters" && c4i == "Kilometers") {
            bres.setText(QString::number(convb.text().toDouble() / 1000));
        } else if (c3i == "Centimeters" && c4i == "Feet") {
            bres.setText(QString::number(convb.text().toDouble() * 0.0328084));
        } else if (c3i == "Centimeters" && c4i == "Inches") {
            bres.setText(QString::number(convb.text().toDouble() * 0.393701));
        } else if (c3i == "Centimeters" && c4i == "Meters") {
            bres.setText(QString::number(convb.text().toDouble() * 0.01));
        } else if (c3i == "Centimeters" && c4i == "Kilometers") {
            bres.setText(QString::number(convb.text().toDouble() / 100000));
        } else if (c3i == "Feet" && c4i == "Meters") {
            bres.setText(QString::number(convb.text().toDouble() / 3.28084));
        } else if (c3i == "Feet" && c4i == "Inches") {
            bres.setText(QString::number(convb.text().toDouble() * 12));
        } else if (c3i == "Feet" && c4i == "Centimeters") {
            bres.setText(QString::number(convb.text().toDouble() * 30.48));
        } else if (c3i == "Feet" && c4i == "Kilometers") {
            bres.setText(QString::number(convb.text().toDouble() / 3280.84));
        } else if (c3i == "Inches" && c4i == "Feet") {
            bres.setText(QString::number(convb.text().toDouble() / 12));
        } else if (c3i == "Inches" && c4i == "Centimeters") {
            bres.setText(QString::number(convb.text().toDouble() * 2.54));
        } else if (c3i == "Inches" && c4i == "Meters") {
            bres.setText(QString::number(convb.text().toDouble() * 0.0254));
        } else if (c3i == "Inches" && c4i == "Kilometers") {
            bres.setText(QString::number(convb.text().toDouble() * 0.0000254));
        } else if (c3i == "Kilometers" && c4i == "Feet") {
            bres.setText(QString::number(convb.text().toDouble() * 3280.84));
        } else if (c3i == "Kilometers" && c4i == "Centimeters") {
            bres.setText(QString::number(convb.text().toDouble() * 100000));
        } else if (c3i == "Kilometers" && c4i == "Meters") {
            bres.setText(QString::number(convb.text().toDouble() * 1000));
        } else if (c3i == "Kilometers" && c4i == "Inches") {
            bres.setText(QString::number(convb.text().toDouble() * 39370.1));
        }
    });

    QLineEdit convc;
    convc.setPlaceholderText("Number:");

    QLabel cres;
    cres.setText("");

    QComboBox c5;
    c5.addItem("Kilograms");
    c5.addItem("Grams");
    c5.addItem("Pounds");
    QObject::connect(&c5, &QComboBox::currentIndexChanged, [&](int index) {
        c5i = c5.itemText(index);
    });

    QComboBox c6;
    c6.addItem("Kilograms");
    c6.addItem("Grams");
    c6.addItem("Pounds");
    QObject::connect(&c6, &QComboBox::currentIndexChanged, [&](int index) {
        c6i = c6.itemText(index);
    });

    QPushButton convert3;
    convert3.setText("Convert");
    QObject::connect(&convert3, &QPushButton::clicked, [&]() {
        if (c5i == c6i) {
            cres.setText(convc.text());
        } else if (c5i == "Kilograms" && c6i == "Grams") {
            cres.setText(QString::number(convc.text().toDouble() * 1000));
        } else if (c5i == "Kilograms" && c6i == "Pounds") {
            cres.setText(QString::number(convc.text().toDouble() * 2.20462262188));
        } else if (c5i == "Grams" && c6i == "Kilograms") {
            cres.setText(QString::number(convc.text().toDouble() / 1000));
        } else if (c5i == "Grams" && c6i == "Pounds") {
            cres.setText(QString::number(convc.text().toDouble() * 0.00220462262188));
        } else if (c5i == "Pounds" && c6i == "Kilograms") {
            cres.setText(QString::number(convc.text().toDouble() * 0.45359237));
        } else if (c5i == "Pounds" && c6i == "Grams") {
            cres.setText(QString::number(convc.text().toDouble() * 453.59237));
        }
    });

    QLabel cftext;
    cftext.setText("Coin Flip");

    QLabel cfr;
    cfr.setText("Flip a coin");

    QPushButton cflip;
    cflip.setText("Flip");
    QObject::connect(&cflip, &QPushButton::clicked, [&]() {
        int rnum = std::rand() % 2;
        std::cout << rnum;
        if (rnum == 0) {
            cfr.setText("Heads!");
        } else {
            cfr.setText("Tails!");
        }
    });

    QGridLayout calcLayout(&calcTab);
    QVBoxLayout memLayout(&memTab);
    QGridLayout convLayout(&convTab);
    QGridLayout probLayout(&probTab);
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
    calcLayout.addWidget(&recip, 3, 2, 1, 1);
    calcLayout.addWidget(&fact, 3, 3, 1, 1);
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
    convLayout.addWidget(&c1, 0, 0);
    convLayout.addWidget(&conva, 0, 1);
    convLayout.addWidget(&c2, 1, 0);
    convLayout.addWidget(&ares, 1, 1);
    convLayout.addWidget(&convert1, 0, 2);
    convLayout.addWidget(&c3, 2, 0);
    convLayout.addWidget(&convb, 2, 1);
    convLayout.addWidget(&c4, 3, 0);
    convLayout.addWidget(&bres, 3, 1);
    convLayout.addWidget(&convert2, 2, 2);
    convLayout.addWidget(&c5, 4, 0);
    convLayout.addWidget(&convc, 4, 1);
    convLayout.addWidget(&c6, 5, 0);
    convLayout.addWidget(&cres, 5, 1);
    convLayout.addWidget(&convert3, 4, 2);
    convLayout.setAlignment(Qt::AlignTop);
    probLayout.addWidget(&cftext, 0, 0, 1, 2);
    probLayout.addWidget(&cflip, 1, 0);
    probLayout.addWidget(&cfr, 1, 1);
    probLayout.setAlignment(Qt::AlignTop);
    tabs.addTab(&calcTab, "Calculator");
    tabs.addTab(&memTab, "Memory");
    tabs.addTab(&convTab, "Convert");
    tabs.addTab(&probTab, "Probability");


    QVBoxLayout mainLayout(&window);
    mainLayout.addWidget(&tabs);

    QPushButton* defButtons[] = {
        &zero, &one, &two, &three, &four, &five,
        &six, &seven, &eight, &nine, &dot, &pi,
        &recip, &fact, &sqrt, &square, &exp,
        &log10, &ln, &sto, &var
    };

    QPushButton* opButtons[] = {
        &delall, &divide, &times, &plus, &minus
    };

    QLabel* memLbl[] = {
        &albl, &blbl, &clbl, &dlbl, &elbl, &flbl
    };

    QLabel* convLbl[] = {
        &ares, &bres, &cres
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
        "    font-size: 48px"
        "}"
    );

    for (QLabel* label : convLbl) {
        label->setStyleSheet(
            "QLabel { border: 1px solid white; "
                "border-radius: 5px}"
        );
    }

    return app.exec();
}