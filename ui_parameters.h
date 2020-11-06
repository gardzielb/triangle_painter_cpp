/********************************************************************************
** Form generated from reading UI file 'ui_parameters.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETERS_H
#define UI_PARAMETERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParametersPanel
{
public:
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QSpinBox *row_spin;
    QSpinBox *col_spin;
    QCheckBox *borders_check;
    QPushButton *reset_grid_button;
    QGroupBox *groupBox_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *light_color_button;
    QGroupBox *groupBox_3;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QPushButton *paint_texture_button;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;
    QPushButton *paint_color_button;
    QGroupBox *groupBox_5;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QGroupBox *groupBox_4;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_5;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_6;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_6;
    QLabel *label_9;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QSlider *horizontalSlider;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QButtonGroup *n_button_group;
    QButtonGroup *color_det_button_group;
    QButtonGroup *paint_button_group;
    QButtonGroup *light_button_group;

    void setupUi(QWidget *ParametersPanel)
    {
        if (ParametersPanel->objectName().isEmpty())
            ParametersPanel->setObjectName(QStringLiteral("ParametersPanel"));
        ParametersPanel->resize(362, 816);
        groupBox = new QGroupBox(ParametersPanel);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 341, 111));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 19, 321, 81));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        row_spin = new QSpinBox(gridLayoutWidget);
        row_spin->setObjectName(QStringLiteral("row_spin"));
        row_spin->setMinimum(1);
        row_spin->setMaximum(1000);

        gridLayout->addWidget(row_spin, 0, 1, 1, 1);

        col_spin = new QSpinBox(gridLayoutWidget);
        col_spin->setObjectName(QStringLiteral("col_spin"));
        col_spin->setMinimum(1);
        col_spin->setMaximum(1000);

        gridLayout->addWidget(col_spin, 1, 1, 1, 1);

        borders_check = new QCheckBox(gridLayoutWidget);
        borders_check->setObjectName(QStringLiteral("borders_check"));
        borders_check->setChecked(true);

        gridLayout->addWidget(borders_check, 2, 0, 1, 1);

        reset_grid_button = new QPushButton(gridLayoutWidget);
        reset_grid_button->setObjectName(QStringLiteral("reset_grid_button"));

        gridLayout->addWidget(reset_grid_button, 2, 1, 1, 1);

        groupBox_2 = new QGroupBox(ParametersPanel);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 130, 341, 101));
        gridLayoutWidget_2 = new QWidget(groupBox_2);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(9, 19, 321, 73));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton = new QRadioButton(gridLayoutWidget_2);
        light_button_group = new QButtonGroup(ParametersPanel);
        light_button_group->setObjectName(QStringLiteral("light_button_group"));
        light_button_group->addButton(radioButton);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setMinimumSize(QSize(154, 0));
        radioButton->setChecked(true);

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(gridLayoutWidget_2);
        light_button_group->addButton(radioButton_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);


        gridLayout_2->addLayout(verticalLayout, 1, 1, 1, 1);

        light_color_button = new QPushButton(gridLayoutWidget_2);
        light_color_button->setObjectName(QStringLiteral("light_color_button"));

        gridLayout_2->addWidget(light_color_button, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(ParametersPanel);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 240, 341, 121));
        gridLayoutWidget_3 = new QWidget(groupBox_3);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 20, 321, 81));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        paint_texture_button = new QPushButton(gridLayoutWidget_3);
        paint_texture_button->setObjectName(QStringLiteral("paint_texture_button"));
        paint_texture_button->setMinimumSize(QSize(156, 0));

        gridLayout_3->addWidget(paint_texture_button, 1, 1, 1, 1);

        radioButton_7 = new QRadioButton(gridLayoutWidget_3);
        paint_button_group = new QButtonGroup(ParametersPanel);
        paint_button_group->setObjectName(QStringLiteral("paint_button_group"));
        paint_button_group->addButton(radioButton_7);
        radioButton_7->setObjectName(QStringLiteral("radioButton_7"));
        radioButton_7->setChecked(true);

        gridLayout_3->addWidget(radioButton_7, 0, 0, 1, 1);

        radioButton_8 = new QRadioButton(gridLayoutWidget_3);
        paint_button_group->addButton(radioButton_8);
        radioButton_8->setObjectName(QStringLiteral("radioButton_8"));

        gridLayout_3->addWidget(radioButton_8, 1, 0, 1, 1);

        paint_color_button = new QPushButton(gridLayoutWidget_3);
        paint_color_button->setObjectName(QStringLiteral("paint_color_button"));

        gridLayout_3->addWidget(paint_color_button, 0, 1, 1, 1);

        groupBox_5 = new QGroupBox(ParametersPanel);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 370, 341, 71));
        gridLayoutWidget_4 = new QWidget(groupBox_5);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(10, 20, 321, 41));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        radioButton_3 = new QRadioButton(gridLayoutWidget_4);
        color_det_button_group = new QButtonGroup(ParametersPanel);
        color_det_button_group->setObjectName(QStringLiteral("color_det_button_group"));
        color_det_button_group->addButton(radioButton_3);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setChecked(true);

        gridLayout_4->addWidget(radioButton_3, 0, 0, 1, 1);

        radioButton_4 = new QRadioButton(gridLayoutWidget_4);
        color_det_button_group->addButton(radioButton_4);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        gridLayout_4->addWidget(radioButton_4, 0, 1, 1, 1);

        groupBox_4 = new QGroupBox(ParametersPanel);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 450, 341, 101));
        gridLayoutWidget_5 = new QWidget(groupBox_4);
        gridLayoutWidget_5->setObjectName(QStringLiteral("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(10, 20, 321, 71));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        radioButton_6 = new QRadioButton(gridLayoutWidget_5);
        n_button_group = new QButtonGroup(ParametersPanel);
        n_button_group->setObjectName(QStringLiteral("n_button_group"));
        n_button_group->addButton(radioButton_6);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));

        gridLayout_5->addWidget(radioButton_6, 1, 0, 1, 1);

        radioButton_5 = new QRadioButton(gridLayoutWidget_5);
        n_button_group->addButton(radioButton_5);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setChecked(true);

        gridLayout_5->addWidget(radioButton_5, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget_5);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_5->addWidget(pushButton_2, 1, 1, 1, 1);

        groupBox_6 = new QGroupBox(ParametersPanel);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 560, 341, 181));
        gridLayoutWidget_6 = new QWidget(groupBox_6);
        gridLayoutWidget_6->setObjectName(QStringLiteral("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(10, 20, 321, 131));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(gridLayoutWidget_6);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_6->addWidget(label_9, 2, 0, 1, 1);

        horizontalSlider_2 = new QSlider(gridLayoutWidget_6);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(horizontalSlider_2, 1, 1, 1, 1);

        horizontalSlider_3 = new QSlider(gridLayoutWidget_6);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(horizontalSlider_3, 2, 1, 1, 1);

        horizontalSlider = new QSlider(gridLayoutWidget_6);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(horizontalSlider, 0, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_6);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_6->addWidget(label_8, 1, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget_6);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_6->addWidget(label_7, 0, 0, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_6);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_6->addWidget(label_10, 0, 2, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_6);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_6->addWidget(label_11, 1, 2, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_6);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_6->addWidget(label_12, 2, 2, 1, 1);


        retranslateUi(ParametersPanel);

        QMetaObject::connectSlotsByName(ParametersPanel);
    } // setupUi

    void retranslateUi(QWidget *ParametersPanel)
    {
        ParametersPanel->setWindowTitle(QApplication::translate("ParametersPanel", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("ParametersPanel", "Triangle grid", nullptr));
        label_2->setText(QApplication::translate("ParametersPanel", "Columns", nullptr));
        label->setText(QApplication::translate("ParametersPanel", "Rows", nullptr));
        borders_check->setText(QApplication::translate("ParametersPanel", "Show triangle borders", nullptr));
        reset_grid_button->setText(QApplication::translate("ParametersPanel", "Reset grid", nullptr));
        groupBox_2->setTitle(QApplication::translate("ParametersPanel", "Light", nullptr));
        label_4->setText(QApplication::translate("ParametersPanel", "Vector", nullptr));
        label_3->setText(QApplication::translate("ParametersPanel", "Color", nullptr));
        radioButton->setText(QApplication::translate("ParametersPanel", "Constant", nullptr));
        radioButton_2->setText(QApplication::translate("ParametersPanel", "Spherical", nullptr));
        light_color_button->setText(QString());
        groupBox_3->setTitle(QApplication::translate("ParametersPanel", "Paint color", nullptr));
        paint_texture_button->setText(QApplication::translate("ParametersPanel", "Choose", nullptr));
        radioButton_7->setText(QApplication::translate("ParametersPanel", "Constant", nullptr));
        radioButton_8->setText(QApplication::translate("ParametersPanel", "Texture", nullptr));
        paint_color_button->setText(QString());
        groupBox_5->setTitle(QApplication::translate("ParametersPanel", "Color determination", nullptr));
        radioButton_3->setText(QApplication::translate("ParametersPanel", "Precise", nullptr));
        radioButton_4->setText(QApplication::translate("ParametersPanel", "From vertices", nullptr));
        groupBox_4->setTitle(QApplication::translate("ParametersPanel", "N vector", nullptr));
        radioButton_6->setText(QApplication::translate("ParametersPanel", "From texture", nullptr));
        radioButton_5->setText(QApplication::translate("ParametersPanel", "Constant", nullptr));
        pushButton_2->setText(QApplication::translate("ParametersPanel", "Choose", nullptr));
        groupBox_6->setTitle(QApplication::translate("ParametersPanel", "Parameters", nullptr));
        label_9->setText(QApplication::translate("ParametersPanel", "m", nullptr));
        label_8->setText(QApplication::translate("ParametersPanel", "ks", nullptr));
        label_7->setText(QApplication::translate("ParametersPanel", "kd", nullptr));
        label_10->setText(QApplication::translate("ParametersPanel", "0", nullptr));
        label_11->setText(QApplication::translate("ParametersPanel", "0", nullptr));
        label_12->setText(QApplication::translate("ParametersPanel", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ParametersPanel: public Ui_ParametersPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETERS_H
