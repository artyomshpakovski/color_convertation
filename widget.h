        #ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <QPixmap>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QGridLayout *grLayout;
private:

    double XYZ_X = 0;
    double XYZ_Y = 0;
    double XYZ_Z = 0;

    double getX() const;
    double getY() const;
    double getZ() const;
    void setX(double);
    void setY(double);
    void setZ(double);

    double LAB_L = 0;
    double LAB_A = 0;
    double LAB_B = 0;

    double getL() const;
    double getA() const;
    double getB() const;
    void setL() const;
    void setA() const;
    void setB() const;

    void paintEvent(QPaintEvent *event);
    void color_convertation_from_QColor();
    void color_convertation_from_XYZ();
    void color_convertation_from_LAB();
    void color_convertation_from_HLS();

    QSlider *sliderLeft;
    QSlider *sliderRight;
    QSlider *sliderCenter;
    QLabel *colorRectangle;

    Ui::Widget *ui;
    QComboBox *cbLeft;
    QComboBox *cbCenter;
    QComboBox *cbRight;
    QStringList slLeft = {"RGB", "CMYK", "HSV", "XYZ"};
    QStringList slCenter = {"LAB", "CMYK", "XYZ", "HSV", "RGB", "HLS"};
    QStringList slRight = {"CMYK", "HLS", "LAB", "HSV", "RGB"};

    QLabel *GradientLabel;

    QLineEdit *leLeftFirst;
    QLineEdit *leLeftSecond;
    QLineEdit *leLeftThird;
    QLineEdit *leLeftFourth;
    QLabel *lbLeftFirst;
    QLabel *lbLeftSecond;
    QLabel *lbLeftThird;
    QLabel *lbLeftFourth;

    QLineEdit *leCenterFirst;
    QLineEdit *leCenterSecond;
    QLineEdit *leCenterThird;
    QLineEdit *leCenterFourth;
    QLabel *lbCenterFirst;
    QLabel *lbCenterSecond;
    QLabel *lbCenterThird;
    QLabel *lbCenterFourth;

    QLineEdit *leRightFirst;
    QLineEdit *leRightSecond;
    QLineEdit *leRightThird;
    QLineEdit *leRightFourth;
    QLabel *lbRightFirst;
    QLabel *lbRightSecond;
    QLabel *lbRightThird;
    QLabel *lbRightFourth;

public slots:

    bool eventFilter(QObject *watched, QEvent *event);

    void Names_For_LeftLabels(QString text);
    void Names_For_CenterLabels(QString text);
    void Names_For_RightLabels(QString text);

    void changed_LeftFirst();
    void changed_LeftSecond();
    void changed_LeftThird();
    void changed_LeftFourth();

    void changed_CenterFirst();
    void changed_CenterSecond();
    void changed_CenterThird();
    void changed_CenterFourth();


    void changed_RightFirst();
    void changed_RightSecond();
    void changed_RightThird();
    void changed_RightFourth();

    void setTexteverywhere();
    void red_change();
    void green_change();
    void blue_change();
    void slidersChanged();

    void setSlider();
    QColor getPixelAt(int x, int y);

};
#endif // WIDGET_H
