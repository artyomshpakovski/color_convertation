#include "widget.h"
#include "ui_widget.h"

QColor main_color; // есть цвета - HSV, RGB, CMYK

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{


    ui->setupUi(this);
    grLayout = new QGridLayout(this);
    qApp->installEventFilter(this);
    grLayout->setAlignment(Qt::AlignLeft);
    setMinimumSize(725,500);
    setMaximumSize(725, 500);
    cbLeft = new QComboBox();
    cbCenter = new QComboBox();
    cbRight = new QComboBox();
    cbLeft->addItems(slLeft);
    cbCenter->addItems(slCenter);
    cbRight->addItems(slRight);
    cbLeft->setCurrentIndex(-1);
    cbRight->setCurrentIndex(-1);
    cbCenter->setCurrentIndex(-1);

    GradientLabel = new QLabel(this);
    grLayout->addWidget(GradientLabel, 1,1,2,7);
    colorRectangle = new QLabel(this);
    grLayout->addWidget(colorRectangle, 3,1, 1, 7);
    colorRectangle->setStyleSheet("QLabel{background-color:rgb(0,0,0);border:0px solid black;}");
    colorRectangle->setMinimumSize(725,10);
    colorRectangle->setMaximumSize(725,10);

    grLayout->addWidget(cbLeft,5,2,1,2);
    grLayout->addWidget(cbCenter,5,4,1,2);
    grLayout->addWidget(cbRight,5,6,1,2);

    lbLeftFirst = new QLabel("R:");
    lbLeftSecond = new QLabel("G:");
    lbLeftThird = new QLabel("B:");
    lbLeftFourth = new QLabel("");
    leLeftFirst = new QLineEdit(this);
    leLeftSecond = new QLineEdit(this);
    leLeftThird = new QLineEdit(this);
    leLeftFourth = new QLineEdit(this);

    grLayout->addWidget(lbLeftFirst, 6,2);
    grLayout->addWidget(leLeftFirst, 6,3);
    grLayout->addWidget(lbLeftSecond, 7, 2);
    grLayout->addWidget(leLeftSecond, 7,3);
    grLayout->addWidget(lbLeftThird, 8, 2);
    grLayout->addWidget(leLeftThird, 8,3);
    grLayout->addWidget(lbLeftFourth, 9, 2);
    grLayout->addWidget(leLeftFourth, 9,3);

    lbCenterFirst = new QLabel("L:");
    lbCenterSecond = new QLabel("A:");
    lbCenterThird = new QLabel("B:");
    lbCenterFourth = new QLabel("");
    leCenterFirst = new QLineEdit(this);
    leCenterSecond = new QLineEdit(this);
    leCenterThird = new QLineEdit(this);
    leCenterFourth = new QLineEdit(this);
    grLayout->addWidget(lbCenterFirst, 6,4);
    grLayout->addWidget(leCenterFirst, 6,5);
    grLayout->addWidget(lbCenterSecond, 7, 4);
    grLayout->addWidget(leCenterSecond, 7,5);
    grLayout->addWidget(lbCenterThird, 8, 4);
    grLayout->addWidget(leCenterThird, 8,5);
    grLayout->addWidget(lbCenterFourth, 9, 4);
    grLayout->addWidget(leCenterFourth, 9,5);

    lbRightFirst = new QLabel("C:");
    lbRightSecond = new QLabel("M:");
    lbRightThird = new QLabel("Y:");
    lbRightFourth = new QLabel("K:");
    leRightFirst = new QLineEdit(this);
    leRightSecond = new QLineEdit(this);
    leRightThird = new QLineEdit(this);
    leRightFourth = new QLineEdit(this);
    grLayout->addWidget(lbRightFirst, 6,6);
    grLayout->addWidget(leRightFirst, 6,7);
    grLayout->addWidget(lbRightSecond, 7, 6);
    grLayout->addWidget(leRightSecond, 7,7);
    grLayout->addWidget(lbRightThird, 8, 6);
    grLayout->addWidget(leRightThird, 8,7);
    grLayout->addWidget(lbRightFourth, 9, 6);
    grLayout->addWidget(leRightFourth, 9,7);

    cbLeft->setCurrentText("RGB");
    cbCenter->setCurrentText("LAB");
    cbRight->setCurrentText("CMYK");
    Names_For_LeftLabels("RGB");
    Names_For_CenterLabels("LAB");
    Names_For_RightLabels("CMYK");
    setLayout(grLayout);


    sliderLeft = new QSlider(this);
    sliderCenter = new QSlider(this);
    sliderRight = new QSlider(this);
    sliderLeft->setOrientation(Qt::Horizontal);
    sliderRight->setOrientation(Qt::Horizontal);
    sliderCenter->setOrientation(Qt::Horizontal);
    sliderLeft->setRange(0, 255);
    sliderCenter->setRange(0, 255);
    sliderRight->setRange(0, 255);
    grLayout->addWidget(sliderLeft, 4, 2, 1, 2);
    grLayout->addWidget(sliderCenter, 4, 4, 1, 2);
    grLayout->addWidget(sliderRight, 4, 6, 1, 2);

    connect(sliderLeft, SIGNAL(valueChanged(int)), this, SLOT(red_change()));
    connect(sliderCenter, SIGNAL(valueChanged(int)), this, SLOT(red_change()));
    connect(sliderRight, SIGNAL(valueChanged(int)), this, SLOT(red_change()));

    connect(cbLeft,SIGNAL(currentTextChanged(QString)),this,SLOT(Names_For_LeftLabels(QString)));
    connect(cbCenter,SIGNAL(currentTextChanged(QString)),this,SLOT(Names_For_CenterLabels(QString)));
    connect(cbRight,SIGNAL(currentTextChanged(QString)),this,SLOT(Names_For_RightLabels(QString)));

    connect(leLeftFirst, SIGNAL(editingFinished()), this, SLOT(changed_LeftFirst()));
    connect(leLeftSecond, SIGNAL(editingFinished()), this, SLOT(changed_LeftSecond()));
    connect(leLeftThird, SIGNAL(editingFinished()), this, SLOT(changed_LeftThird()));
    connect(leLeftFourth, SIGNAL(editingFinished()), this, SLOT(changed_LeftFourth()));

    connect(leCenterFirst, SIGNAL(editingFinished()), this, SLOT(changed_CenterFirst()));
    connect(leCenterSecond, SIGNAL(editingFinished()), this, SLOT(changed_CenterSecond()));
    connect(leCenterThird, SIGNAL(editingFinished()), this, SLOT(changed_CenterThird()));
    connect(leCenterFourth, SIGNAL(editingFinished()), this, SLOT(changed_CenterFourth()));

    connect(leRightFirst, SIGNAL(editingFinished()), this, SLOT(changed_RightFirst()));
    connect(leRightSecond, SIGNAL(editingFinished()), this, SLOT(changed_RightSecond()));
    connect(leRightThird, SIGNAL(editingFinished()), this, SLOT(changed_RightThird()));
    connect(leRightFourth, SIGNAL(editingFinished()), this, SLOT(changed_RightFourth()));

    connect(sliderLeft, SIGNAL(valueChanged(int)), this, SLOT(slidersChanged()));
    connect(sliderCenter, SIGNAL(valueChanged(int)), this, SLOT(slidersChanged()));
    connect(sliderRight, SIGNAL(valueChanged(int)), this, SLOT(slidersChanged()));
}

Widget::~Widget()
{
    delete ui;
}

double Widget::getY() const
{
    return XYZ_Y;
}

double Widget::getX() const
{
    return XYZ_X;
}

double Widget::getZ() const
{
    return XYZ_Z;
}

void Widget::setX(double x)
{
    XYZ_X = x;
}

void Widget::setY(double x)
{
    XYZ_Y = x;
}

void Widget::setZ(double x)
{
    XYZ_Z = x;
}



void Widget::Names_For_LeftLabels(QString text)
{
    leLeftFourth->hide();
    if (text == "RGB") {
        lbLeftFirst->setText("R:");
        lbLeftSecond->setText("G:");
        lbLeftThird->setText("B:");
        lbLeftFourth->setText("");
    }
    if (text == "HSV") {
        lbLeftFirst->setText("H:");
        lbLeftSecond->setText("S:");
        lbLeftThird->setText("V:");
        lbLeftFourth->setText("");
    }
    if (text == "XYZ") {
        lbLeftFirst->setText("X:");
        lbLeftSecond->setText("Y:");
        lbLeftThird->setText("Z:");
        lbLeftFourth->setText("");
    }
    if (text == "CMYK") {
        lbLeftFirst->setText("C:");
        lbLeftSecond->setText("M:");
        lbLeftThird->setText("Y:");
        lbLeftFourth->setText("K:");
        leLeftFourth->show();
    }

    setTexteverywhere();
}

void Widget::Names_For_CenterLabels(QString text)
{
    leCenterFourth->hide();
    if (text == "RGB") {
        lbCenterFirst->setText("R:");
        lbCenterSecond->setText("G:");
        lbCenterThird->setText("B:");
        lbCenterFourth->setText("");
    }
    if (text == "HSV") {
        lbCenterFirst->setText("H:");
        lbCenterSecond->setText("S:");
        lbCenterThird->setText("V:");
        lbCenterFourth->setText("");
    }
    if (text == "XYZ") {
        lbCenterFirst->setText("X:");
        lbCenterSecond->setText("Y:");
        lbCenterThird->setText("Z:");
        lbCenterFourth->setText("");
    }
    if (text == "CMYK") {
        lbCenterFirst->setText("C:");
        lbCenterSecond->setText("M:");
        lbCenterThird->setText("Y:");
        lbCenterFourth->setText("K:");
        leCenterFourth->show();
    }
    if (text == "HLS") {
        lbCenterFirst->setText("H:");
        lbCenterSecond->setText("L:");
        lbCenterThird->setText("S:");
        lbCenterFourth->setText("");
    }
    if (text == "LAB") {
        lbCenterFirst->setText("L:");
        lbCenterSecond->setText("A:");
        lbCenterThird->setText("B:");
        lbCenterFourth->setText("");
    }

    setTexteverywhere();
}

void Widget::Names_For_RightLabels(QString text)
{
    leRightFourth->hide();
    if (text == "CMYK") {
        lbRightFirst->setText("C:");
        lbRightSecond->setText("M:");
        lbRightThird->setText("Y:");
        lbRightFourth->setText("K:");
        leRightFourth->show();
    }
    if (text == "HLS") {
        lbRightFirst->setText("H:");
        lbRightSecond->setText("L:");
        lbRightThird->setText("S:");
        lbRightFourth->setText("");
    }
    if (text == "LAB") {
        lbRightFirst->setText("L:");
        lbRightSecond->setText("A:");
        lbRightThird->setText("B:");
        lbRightFourth->setText("");
    }
    if (text == "HSV") {
        lbRightFirst->setText("H:");
        lbRightSecond->setText("S:");
        lbRightThird->setText("V:");
        lbRightFourth->setText("");
    }
    if (text == "RGB") {
        lbRightFirst->setText("R:");
        lbRightSecond->setText("G:");
        lbRightThird->setText("B:");
        lbRightFourth->setText("");
    }

    setTexteverywhere();
}

void Widget::changed_LeftFirst()
{
    if (cbLeft->currentText() == "RGB") {
        main_color.setRed(leLeftFirst->text().toInt());
        color_convertation_from_QColor();
    }

    if (lbLeftFirst->text() == "C:") {
        main_color.setCmyk(leLeftFirst->text().toInt(), main_color.magenta(), main_color.yellow(), main_color.black());
        color_convertation_from_QColor();
    }

    if (lbLeftFirst->text() == "H:") {
        main_color.setHsv(leLeftFirst->text().toInt(), main_color.saturation(), main_color.value());
        color_convertation_from_QColor();
    }

    if (lbLeftFirst->text() == "X:") {
        setX(lbLeftFirst->text().toDouble());
        color_convertation_from_XYZ();
    }

    setSlider();
    setTexteverywhere();
}

void Widget::changed_LeftSecond()
{
    if (lbLeftSecond->text() == "G:") {
        main_color.setGreen(leLeftSecond->text().toInt());
        color_convertation_from_QColor();
    }

    if (lbLeftSecond->text() == "M:") {
        main_color.setCmyk(main_color.cyan(), leLeftSecond->text().toInt(), main_color.yellow(), main_color.black());
        color_convertation_from_QColor();
    }

    if (lbLeftSecond->text() == "S:") {
        main_color.setHsv(main_color.hue(), leLeftSecond->text().toInt(), main_color.value());
        color_convertation_from_QColor();
    }

    if (cbCenter->currentText() == "XYZ") {
        setY(lbLeftSecond->text().toDouble());
        color_convertation_from_XYZ();
    }

    setSlider();
    setTexteverywhere();
}

void Widget::changed_LeftThird()
{
    if (lbLeftThird->text() == "B:") {
        main_color.setBlue(leLeftThird->text().toInt());
        color_convertation_from_QColor();
    }

    if (lbLeftThird->text() == "Y:") {
        main_color.setCmyk(main_color.cyan(), main_color.magenta(), leLeftThird->text().toInt(), main_color.black());
        color_convertation_from_QColor();
    }

    if (lbLeftThird->text() == "V:") {
        main_color.setHsv(main_color.hue(), main_color.saturation(), leLeftThird->text().toInt());
        color_convertation_from_QColor();
    }

    if (lbLeftThird->text() == "Z:") {
        setZ(lbLeftThird->text().toDouble());
        color_convertation_from_XYZ();
    }

    setSlider();
    setTexteverywhere();
}

void Widget::changed_LeftFourth()
{
    main_color.setCmyk(main_color.cyan(), main_color.magenta(), main_color.yellow(), leLeftFourth->text().toInt());
    color_convertation_from_QColor();
    setSlider();
    setTexteverywhere();
}

void Widget::changed_CenterFirst()
{
    if (cbCenter->currentText() == "LAB") {
        LAB_L = leCenterFirst->text().toDouble();
        color_convertation_from_LAB();
    }

    if (cbCenter->currentText() == "CMYK") {
        main_color.setCmyk(leCenterFirst->text().toInt(), main_color.magenta(), main_color.yellow(), main_color.black());
        color_convertation_from_QColor();
    }

    if (lbCenterFirst->text() == "X:") {
        setX(lbCenterFirst->text().toDouble());
        color_convertation_from_XYZ();
    }

    if (cbCenter->currentText() == "HSV") {
        main_color.setHsv(leCenterFirst->text().toInt(), main_color.saturation(), main_color.value());
        color_convertation_from_QColor();
    }

    if (lbCenterFirst->text() == "R:") {
        XYZ_X = leLeftFirst->text().toDouble();
        XYZ_Y = leLeftSecond->text().toDouble();
        XYZ_Z = leLeftThird->text().toDouble();
        color_convertation_from_XYZ();
    }

    if (cbCenter->currentText() == "HLS") {
        main_color.setHsl(leCenterFirst->text().toDouble(), main_color.lightness(), main_color.hslSaturation());
        color_convertation_from_QColor();
    }

    setSlider();
    setTexteverywhere();
}

void Widget::changed_CenterSecond()
{
    if (cbCenter->currentText() == "LAB") {
        LAB_A = leCenterSecond->text().toDouble();
        color_convertation_from_LAB();
    }

    if (lbCenterSecond->text() == "M:") {
        main_color.setCmyk(main_color.cyan(),leCenterSecond->text().toInt(),  main_color.yellow(), main_color.black());
        color_convertation_from_QColor();
    }

    if (lbCenterSecond->text() == "Y:") {
        setY(lbCenterSecond->text().toDouble());
        color_convertation_from_XYZ();
    }

    if (cbCenter->currentText() == "HSV") {
        main_color.setHsv(main_color.hue(), leCenterSecond->text().toInt(), main_color.value());
        color_convertation_from_QColor();
    }

    if (lbCenterSecond->text() == "G:") {
        main_color.setGreen(leCenterSecond->text().toInt());
        color_convertation_from_QColor();
    }

    if (cbCenter->currentText() == "HLS") {
        main_color.setHsl(main_color.hslHue(), leCenterSecond->text().toDouble(), main_color.hslSaturation());
        color_convertation_from_QColor();
    }

    setSlider();
    setTexteverywhere();
}

void Widget::changed_CenterThird()
{
    if (cbCenter->currentText() == "LAB") {
        LAB_B = leCenterThird->text().toDouble();
        color_convertation_from_LAB();
    }

    if (cbCenter->currentText() == "CMYK") {
        main_color.setCmyk(main_color.cyan(), main_color.magenta(), leCenterThird->text().toInt(), main_color.black());
        color_convertation_from_QColor();
    }

    if (cbCenter->currentText() == "XYZ") {
        setZ(lbCenterThird->text().toDouble());
        color_convertation_from_XYZ();
    }

    if (cbCenter->currentText() == "HSV") {
        main_color.setHsv(main_color.hue(), main_color.saturation(), leCenterThird->text().toInt());
        color_convertation_from_QColor();
    }

    if (cbCenter->currentText() == "RGB") {
        main_color.setBlue(leCenterThird->text().toInt());
        color_convertation_from_QColor();
    }

    if (cbCenter->currentText() == "HLS") { // S
        main_color.setHsl(main_color.hslHue(), main_color.lightness(), leRightThird->text().toDouble());
        color_convertation_from_QColor();
    }

    setSlider();
    setTexteverywhere();
}

void Widget::changed_CenterFourth()
{
    main_color.setCmyk(main_color.cyan(), main_color.magenta(), main_color.yellow(), leCenterFourth->text().toInt());
    color_convertation_from_QColor();
    setSlider();
    setTexteverywhere();
}

void Widget::changed_RightFirst()
{
    if (cbRight->currentText() == "CMYK") {
        main_color.setCmyk(leRightFirst->text().toInt(), main_color.magenta(), main_color.yellow(), main_color.black());
        color_convertation_from_QColor();
    }

    if (cbRight->currentText() == "HLS") { // H
        main_color.setHsl(leRightFirst->text().toDouble(), main_color.saturation(), main_color.lightness());
        color_convertation_from_QColor();
    }

    if (cbRight->currentText() == "LAB") {
        LAB_L = leRightFirst->text().toDouble();
        color_convertation_from_LAB();
    }

    if (cbRight->currentText() == "HSV") {
        main_color.setHsv(leRightFirst->text().toInt(), main_color.saturation(), main_color.value());
        color_convertation_from_QColor();
    }

    if (cbRight->currentText() == "RGB") {
        main_color.setRed(leRightFirst->text().toInt());
        color_convertation_from_QColor();
    }

    setSlider();
    setTexteverywhere();
}

void Widget::changed_RightSecond()
{
    if (cbRight->currentText() == "CMYK") {
        main_color.setCmyk(main_color.cyan(),leRightSecond->text().toInt(),  main_color.yellow(), main_color.black());
        color_convertation_from_QColor();
    }

    if (cbRight->currentText() == "HLS") { // L
        main_color.setHsl(main_color.hslHue(), leRightSecond->text().toDouble(), main_color.hslSaturation());
        color_convertation_from_QColor();
    }

    if (cbRight->currentText() == "LAB") {
        LAB_A = leRightSecond->text().toDouble();
        color_convertation_from_LAB();
    }

    if (cbRight->currentText() == "HSV") {
        main_color.setHsv(main_color.hue(),leRightFirst->text().toInt(),  main_color.value());
        color_convertation_from_QColor();
    }

    if (cbRight->currentText() == "RGB") {
        main_color.setGreen(leRightSecond->text().toInt());
        color_convertation_from_QColor();
    }

    setSlider();
    setTexteverywhere();

}

void Widget::changed_RightThird()
{

    if (cbRight->currentText() == "CMYK") {
        main_color.setCmyk(main_color.cyan(),  main_color.magenta(),leRightThird->text().toInt(), main_color.black());
        color_convertation_from_QColor();
    }

    if (cbRight->currentText() == "HLS") { // это S
        main_color.setHsl(main_color.hslHue(), main_color.lightness(), leRightThird->text().toInt());
        color_convertation_from_QColor();
    }

    if (cbRight->currentText() == "LAB") {
        LAB_B = leRightThird->text().toDouble();
        color_convertation_from_LAB();
    }

    if (cbRight->currentText() == "HSV") {
        main_color.setHsv(main_color.hue(), main_color.saturation(), leRightSecond->text().toDouble());
        color_convertation_from_QColor();
    }

    if (cbRight->currentText() == "RGB") {
        main_color.setBlue(leRightThird->text().toInt());
        color_convertation_from_QColor();
    }

    setSlider();
    setTexteverywhere();
}

void Widget::changed_RightFourth()
{
    main_color.setCmyk(main_color.cyan(), main_color.magenta(), main_color.yellow(), leRightFourth->text().toInt());
    color_convertation_from_QColor();
    setSlider();
    setTexteverywhere();
}

void Widget::setTexteverywhere()
{
    if (cbLeft->currentText() == "RGB") {
        leLeftFirst->setText(QString::number(main_color.red()));
        leLeftSecond->setText(QString::number(main_color.green()));
        leLeftThird->setText(QString::number(main_color.blue()));
    }

    if (cbLeft->currentText() == "HSV") {
        leLeftFirst->setText(QString::number(main_color.hue()));
        leLeftSecond->setText(QString::number(main_color.saturation()));
        leLeftThird->setText(QString::number(main_color.value()));
    }

    if (cbLeft->currentText() == "XYZ") {
        leLeftFirst -> setText(QString::number(getX()));
        leLeftSecond -> setText(QString::number(getY()));
        leLeftThird -> setText(QString::number(getZ()));
    }

    if (cbLeft->currentText() == "CMYK") {
        leLeftFirst -> setText(QString::number(main_color.cyan()));
        leLeftSecond->setText(QString::number(main_color.magenta()));
        leLeftThird->setText(QString::number(main_color.yellow()));
        leLeftFourth->setText(QString::number(main_color.black()));
    }

    if (cbCenter->currentText() == "LAB") {
        leCenterFirst -> setText(QString::number(LAB_L));
        leCenterSecond->setText(QString::number(LAB_A));
        leCenterThird->setText(QString::number(LAB_B));
    }

    if (cbCenter->currentText() == "CMYK") {
        leCenterFirst -> setText(QString::number(main_color.cyan()));
        leCenterSecond->setText(QString::number(main_color.magenta()));
        leCenterThird->setText(QString::number(main_color.yellow()));
        leCenterFourth->setText(QString::number(main_color.black()));
    }

    if (cbCenter->currentText() == "XYZ") {
        leCenterFirst -> setText(QString::number(getX()));
        leCenterSecond -> setText(QString::number(getY()));
        leCenterThird -> setText(QString::number(getZ()));
    }

    if (cbCenter->currentText() == "HSV") {
        leCenterFirst->setText(QString::number(main_color.hue()));
        leCenterSecond->setText(QString::number(main_color.saturation()));
        leCenterThird->setText(QString::number(main_color.value()));
    }

    if (cbCenter->currentText() == "RGB") {
        leCenterFirst->setText(QString::number(main_color.red()));
        leCenterSecond->setText(QString::number(main_color.green()));
        leCenterThird->setText(QString::number(main_color.blue()));
    }

    if (cbCenter->currentText() == "HLS") {
        leCenterFirst->setText(QString::number(main_color.hslHue()));
        leCenterSecond->setText(QString::number(main_color.lightness()));
        leCenterThird->setText(QString::number(main_color.hslSaturation()));
    }

    if (cbRight->currentText() == "CMYK") {
        leRightFirst->setText(QString::number(main_color.cyan()));
        leRightSecond->setText(QString::number(main_color.magenta()));
        leRightThird->setText(QString::number(main_color.yellow()));
        leRightFourth->setText(QString::number(main_color.black()));
    }

    if (cbRight->currentText() == "HLS") {
        leRightFirst->setText(QString::number(main_color.hslHue()));
        leRightSecond->setText(QString::number(main_color.lightness()));
        leRightThird->setText(QString::number(main_color.hslSaturation()));
    }

    if (cbRight->currentText() == "LAB") {
        leRightFirst -> setText(QString::number(LAB_L));
        leRightSecond->setText(QString::number(LAB_A));
        leRightThird->setText(QString::number(LAB_B));
    }

    if (cbRight->currentText() == "HSV") {
        leRightFirst->setText(QString::number(main_color.hue()));
        leRightSecond->setText(QString::number(main_color.saturation()));
        leRightThird->setText(QString::number(main_color.value()));
    }

    if (cbRight->currentText() == "RGB") {
        leRightFirst->setText(QString::number(main_color.red()));
        leRightSecond->setText(QString::number(main_color.green()));
        leRightThird->setText(QString::number(main_color.blue()));
    }
}

void Widget::red_change()
{
    main_color.setRed(sliderLeft->value());
    main_color.setGreen(sliderCenter->value());
    main_color.setBlue(sliderRight->value());
    color_convertation_from_QColor();
    QString r = QString::number(main_color.red());
    QString g = QString::number(main_color.green());
    QString b = QString::number(main_color.blue());
    colorRectangle->setStyleSheet("QLabel{background-color:rgb("+r+
                                  ","+g+","+b+");}");
    setTexteverywhere();
}

void Widget::green_change()
{
    QString r = QString::number(sliderCenter->value());
}

void Widget::blue_change()
{
    QString r = QString::number(sliderCenter->value());
}

void Widget::slidersChanged()
{
}

void Widget::setSlider()
{
    sliderLeft->setValue(main_color.red());
    sliderCenter->setValue(main_color.green());
    sliderRight->setValue(main_color.blue());
}

QColor Widget::getPixelAt(int x, int y)
{
    return grab(QRect(x, y, 1, 1)).toImage().pixelColor(0,0);
}

double F_RGB_XYZ(double x) {
    if (x>=0.04045) {
        return pow((x+0.055)/1.055, 2.4);
    }
    return x/12.92;
}

double F_XYZ_LAB(double x) {
    if (x >= 0.008856) {
        return pow(x, 1.0/3.0);
    }
    return 7.787 * x + 16.0 /(double) 116.0;
}

void Widget::color_convertation_from_QColor() {

    double Rn = F_RGB_XYZ(main_color.red() / 255.0);
    double Gn = F_RGB_XYZ(main_color.green() / 255.0);
    double Bn = F_RGB_XYZ(main_color.blue() / 255.0);

    double XYZ_X1 = 0.412453*Rn + 0.357580 * Gn + 0.180423 * Bn;
    double XYZ_Y1 = 0.212671*Rn + 0.715160 * Gn + 0.072169 * Bn;
    double XYZ_Z1 = 0.019334*Rn + 0.119193 * Gn + 0.950227 * Bn;

    XYZ_X1*=100.0;
    XYZ_Y1*=100.0;
    XYZ_Z1*=100.0;

    setX(XYZ_X1);
    setY(XYZ_Y1);
    setZ(XYZ_Z1);

    double X = XYZ_X1 / 95.047;
    double Y = XYZ_Y1 / 100.0;
    double Z = XYZ_Z1 / 108.883;

    LAB_L = 116 * F_XYZ_LAB(Y) - 16;
    LAB_A = 500 * (F_XYZ_LAB(X) - F_XYZ_LAB(Y));
    LAB_B = 200 * (F_XYZ_LAB(Y) - F_XYZ_LAB(Z));
}

double F_XYZ_RGB(double x) {
    if (abs(x)<0.0031308) {
        return 12.92 * x;
    }

    return 1.055 * pow(x, 0.41666) - 0.055;
}

void Widget::color_convertation_from_XYZ() {

    double X = getX();
    double Y = getY();
    double Z = getZ();

    double Rn = 3.2404542 * X - 1.5371385 * Y  - 0.4985314 * Z;
    double Gn = -0.9692660 * X + 1.8760108 * Y  + 0.0415560 * Z;
    double Bn = 0.0556434 * X - 0.2040259 * Y  + 1.0572252 * Z;

    Rn/=100.0;
    Gn/=100.0;
    Bn/=100.0;

    double R = F_XYZ_RGB(Rn);
    double G = F_XYZ_RGB(Gn);
    double B = F_XYZ_RGB(Bn);

    R*=255.0;
    G*=255.0;
    B*=255.0;

    main_color.setRed(round(R));
    main_color.setGreen(round(G));
    main_color.setBlue(round(B));

    LAB_L = 116 * F_XYZ_LAB(X/(double) 100.0)-16;
    LAB_A = 500 * (F_XYZ_LAB(X/95.047)-F_XYZ_LAB(Y/(double) 100.0));
    LAB_B = 200 * (F_XYZ_LAB(Y/(double) 100.0)- F_XYZ_LAB(Z/(double) 108.883));

}

double F_LAB_XYZ(double x) {
    if (pow(x,3)>=0.008856) {
        return pow(x,3);
    }
    return (x-16.0/116.0)/7.878;
}

void Widget::color_convertation_from_LAB() {
    double XYZ_X1 = F_LAB_XYZ(LAB_A/500.0+(LAB_L+16.0)/116.0) * 95.047;
    double XYZ_Y1 = F_LAB_XYZ((LAB_L+16.0)/116.0) * 100.0;
    double XYZ_Z1 = F_LAB_XYZ((LAB_L+16.0)/116.0-LAB_B/200) * 108.883;

    setX(XYZ_X1);
    setY(XYZ_Y1);
    setZ(XYZ_Z1);

    double Rn = 3.2406 * XYZ_X1 / 100 - 1.5372 * XYZ_Y1 / 100 - 0.4986 * XYZ_Z1 / 100;
    double Gn = -0.9689 * XYZ_X1 / 100 + 1.8758 * XYZ_Y1 / 100 + 0.0415 * XYZ_Z1 / 100;
    double Bn = 0.0557 * XYZ_X1 / 100 - 0.2040 * XYZ_Y1 / 100 + 1.0570 * XYZ_Z1 / 100;

    main_color.setRed(round(F_XYZ_RGB(Rn)*255));
    main_color.setGreen(round(F_XYZ_RGB(Gn)*255));
    main_color.setBlue(round(F_XYZ_RGB(Bn)*255));
}

void Widget::paintEvent(QPaintEvent *event) {
    /*
    QWidget::paintEvent(event);
    GradientLabel->setMinimumSize(725, 250);
    GradientLabel->setMaximumSize(725, 250);
    QPixmap Grad(GradientLabel->width(), GradientLabel->height());
    QPainter paint(&Grad);
    QLinearGradient linearGradient(0, 0, Grad.width(), Grad.height());
    linearGradient.setColorAt(0.0, Qt::red);
    linearGradient.setColorAt(0.2, Qt::yellow);
    linearGradient.setColorAt(0.5, Qt::green);
    linearGradient.setColorAt(0.7, Qt::blue);
    linearGradient.setColorAt(1.0, Qt::magenta);
    GradientLabel->setPixmap(Grad);
    paint.setBrush(linearGradient);
    paint.drawRect(0,0,GradientLabel->width()-1, GradientLabel->height()-1);
    GradientLabel->update();
    */

    QPixmap pix(GradientLabel->width(),GradientLabel->height());
    QPixmap pix2(GradientLabel->width(),GradientLabel->height());
    QPainter painter(&pix);
    QPainter painter2(&pix2);
    QLinearGradient gradl(0,0,pix.width(),0);
    gradl.setColorAt(0,Qt::red);
    gradl.setColorAt(0.18,Qt::yellow);
    gradl.setColorAt(0.36,Qt::green);
    gradl.setColorAt(0.54,Qt::blue);
    gradl.setColorAt(0.8,Qt::darkBlue);
    gradl.setColorAt(1,Qt::magenta);
    painter.setBrush(gradl);
    painter.drawRect(0,0,GradientLabel->width(),GradientLabel->height());
    GradientLabel->setPixmap(pix);
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress && watched == GradientLabel) {
        QMouseEvent* cur = dynamic_cast<QMouseEvent*>(event);
        int x = cur->pos().x() + GradientLabel->x();
        int y = cur->pos().y() + GradientLabel->y();
        main_color = QWidget::grab(QRect(x,y,1,1)).toImage().pixelColor(0,0);
        setTexteverywhere();
        setSlider();
    }

    return false;
}


