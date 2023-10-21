/********************************************************************************
** Form generated from reading UI file 'player.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYER_H
#define UI_PLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "videowidget.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *Head_Bar;
    QHBoxLayout *horizontalLayout_15;
    QFrame *Head_BTNS_CONATINER_3;
    QHBoxLayout *horizontalLayout_16;
    QLabel *About;
    QPushButton *MiniMize_4;
    QPushButton *Full_Restore_Screen_4;
    QPushButton *Exit_4;
    videowidget *video_player;
    QVBoxLayout *verticalLayout_2;
    QWidget *Bottom;
    QVBoxLayout *verticalLayout_5;
    QFrame *Bottom_Elems_parent_2;
    QVBoxLayout *verticalLayout_6;
    QFrame *Progress_Conatiner_2;
    QVBoxLayout *verticalLayout_3;
    QSlider *Video_LEngth_2;
    QFrame *Bottom_Buttons_2;
    QHBoxLayout *horizontalLayout_11;
    QFrame *Play_Audio_backgward_BTN;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Play_PAUSe;
    QPushButton *BackWard;
    QWidget *Audio_Controller_Container;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Audio;
    QSlider *Audio_Slider;
    QLabel *currVolume;
    QSpacerItem *horizontalSpacer;
    QFrame *Container_2;
    QHBoxLayout *horizontalLayout;
    QLabel *Video_length;
    QPushButton *openFile;
    QPushButton *Btm_fullScreen;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1140, 836);
        Widget->setStyleSheet(QString::fromUtf8("#Widget{background-color:black;;\n"
"	font: 700 14pt \"Segoe UI\";\n"
"}\n"
"Head_Bar{\n"
"	background-color:transparent;\n"
"}\n"
"QToolTip{\n"
"	color:red;\n"
"	border: 2px solid purple;\n"
"	font: 700 13pt \"Segoe UI\";\n"
"\n"
"}"));
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Head_Bar = new QWidget(Widget);
        Head_Bar->setObjectName("Head_Bar");
        horizontalLayout_15 = new QHBoxLayout(Head_Bar);
        horizontalLayout_15->setSpacing(0);
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        Head_BTNS_CONATINER_3 = new QFrame(Head_Bar);
        Head_BTNS_CONATINER_3->setObjectName("Head_BTNS_CONATINER_3");
        Head_BTNS_CONATINER_3->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color:transparent;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgb(121, 121, 121)\n"
"\n"
"}"));
        Head_BTNS_CONATINER_3->setFrameShape(QFrame::StyledPanel);
        Head_BTNS_CONATINER_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_16 = new QHBoxLayout(Head_BTNS_CONATINER_3);
        horizontalLayout_16->setSpacing(0);
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        About = new QLabel(Head_BTNS_CONATINER_3);
        About->setObjectName("About");

        horizontalLayout_16->addWidget(About);

        MiniMize_4 = new QPushButton(Head_BTNS_CONATINER_3);
        MiniMize_4->setObjectName("MiniMize_4");
        MiniMize_4->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/Resoruces/MiniMize.png"), QSize(), QIcon::Normal, QIcon::Off);
        MiniMize_4->setIcon(icon);
        MiniMize_4->setIconSize(QSize(27, 27));

        horizontalLayout_16->addWidget(MiniMize_4);

        Full_Restore_Screen_4 = new QPushButton(Head_BTNS_CONATINER_3);
        Full_Restore_Screen_4->setObjectName("Full_Restore_Screen_4");
        Full_Restore_Screen_4->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/Resoruces/fullScreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        Full_Restore_Screen_4->setIcon(icon1);
        Full_Restore_Screen_4->setIconSize(QSize(27, 27));

        horizontalLayout_16->addWidget(Full_Restore_Screen_4);

        Exit_4 = new QPushButton(Head_BTNS_CONATINER_3);
        Exit_4->setObjectName("Exit_4");
        Exit_4->setCursor(QCursor(Qt::PointingHandCursor));
        Exit_4->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/Resoruces/Exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        Exit_4->setIcon(icon2);
        Exit_4->setIconSize(QSize(27, 27));

        horizontalLayout_16->addWidget(Exit_4);


        horizontalLayout_15->addWidget(Head_BTNS_CONATINER_3, 0, Qt::AlignRight|Qt::AlignTop);


        verticalLayout->addWidget(Head_Bar);

        video_player = new videowidget(Widget);
        video_player->setObjectName("video_player");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(video_player->sizePolicy().hasHeightForWidth());
        video_player->setSizePolicy(sizePolicy);
        video_player->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(video_player);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(video_player);

        Bottom = new QWidget(Widget);
        Bottom->setObjectName("Bottom");
        Bottom->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color:transparent;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgb(85, 85, 85)\n"
"}\n"
"QToolButton\n"
"{\n"
"	background-color:transparent;\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(Bottom);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        Bottom_Elems_parent_2 = new QFrame(Bottom);
        Bottom_Elems_parent_2->setObjectName("Bottom_Elems_parent_2");
        Bottom_Elems_parent_2->setFrameShape(QFrame::StyledPanel);
        Bottom_Elems_parent_2->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(Bottom_Elems_parent_2);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        Progress_Conatiner_2 = new QFrame(Bottom_Elems_parent_2);
        Progress_Conatiner_2->setObjectName("Progress_Conatiner_2");
        Progress_Conatiner_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	font: 900 14pt \"Segoe UI\";\n"
"}\n"
"QSlider\n"
"{\n"
"	height:14px;\n"
"	border-radius:5px;\n"
"}\n"
"QSlider::handle\n"
"{\n"
"	background-color:qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.05 rgba(14, 8, 73, 255), stop:0.36 rgba(28, 17, 145, 255), stop:0.6 rgba(126, 14, 81, 255), stop:0.75 rgba(234, 11, 11, 255), stop:0.79 rgba(244, 70, 5, 255), stop:0.86 rgba(255, 136, 0, 255), stop:0.935 rgba(239, 236, 55, 255));\n"
"	border: 1px solid black;\n"
"	border-radius: 5px;\n"
"	height:15px;\n"
"}\n"
"QSlider::sub-page\n"
"{\n"
"	background-color:qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(0, 0, 0, 255), stop:0.05 rgba(14, 8, 73, 255), stop:0.36 rgba(28, 17, 145, 255), stop:0.6 rgba(126, 14, 81, 255), stop:0.75 rgba(234, 11, 11, 255), stop:0.79 rgba(244, 70, 5, 255), stop:0.86 rgba(255, 136, 0, 255), stop:0.935 rgba(239, 236, 55, 255));\n"
"}\n"
"QSlider::add-page\n"
"{\n"
"	background-color:rgb(184, 184, 184);\n"
"}"));
        Progress_Conatiner_2->setFrameShape(QFrame::StyledPanel);
        Progress_Conatiner_2->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(Progress_Conatiner_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        Video_LEngth_2 = new QSlider(Progress_Conatiner_2);
        Video_LEngth_2->setObjectName("Video_LEngth_2");
        Video_LEngth_2->setCursor(QCursor(Qt::PointingHandCursor));
        Video_LEngth_2->setMouseTracking(false);
        Video_LEngth_2->setStyleSheet(QString::fromUtf8(""));
        Video_LEngth_2->setMinimum(0);
        Video_LEngth_2->setMaximum(0);
        Video_LEngth_2->setValue(0);
        Video_LEngth_2->setSliderPosition(0);
        Video_LEngth_2->setOrientation(Qt::Horizontal);
        Video_LEngth_2->setInvertedAppearance(false);
        Video_LEngth_2->setInvertedControls(false);

        verticalLayout_3->addWidget(Video_LEngth_2);


        verticalLayout_6->addWidget(Progress_Conatiner_2);

        Bottom_Buttons_2 = new QFrame(Bottom_Elems_parent_2);
        Bottom_Buttons_2->setObjectName("Bottom_Buttons_2");
        Bottom_Buttons_2->setFrameShape(QFrame::StyledPanel);
        Bottom_Buttons_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_11 = new QHBoxLayout(Bottom_Buttons_2);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        Play_Audio_backgward_BTN = new QFrame(Bottom_Buttons_2);
        Play_Audio_backgward_BTN->setObjectName("Play_Audio_backgward_BTN");
        Play_Audio_backgward_BTN->setMinimumSize(QSize(250, 0));
        Play_Audio_backgward_BTN->setFrameShape(QFrame::StyledPanel);
        Play_Audio_backgward_BTN->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(Play_Audio_backgward_BTN);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        Play_PAUSe = new QPushButton(Play_Audio_backgward_BTN);
        Play_PAUSe->setObjectName("Play_PAUSe");
        Play_PAUSe->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/Resoruces/Play.png"), QSize(), QIcon::Normal, QIcon::Off);
        Play_PAUSe->setIcon(icon3);
        Play_PAUSe->setIconSize(QSize(35, 35));

        horizontalLayout_3->addWidget(Play_PAUSe);

        BackWard = new QPushButton(Play_Audio_backgward_BTN);
        BackWard->setObjectName("BackWard");
        BackWard->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icons/Resoruces/reWind.png"), QSize(), QIcon::Normal, QIcon::Off);
        BackWard->setIcon(icon4);
        BackWard->setIconSize(QSize(33, 27));

        horizontalLayout_3->addWidget(BackWard);

        Audio_Controller_Container = new QWidget(Play_Audio_backgward_BTN);
        Audio_Controller_Container->setObjectName("Audio_Controller_Container");
        Audio_Controller_Container->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color:white;\n"
"	font: 700 12pt \"Segoe UI\";\n"
"}\n"
"\n"
"QSlider\n"
"{\n"
"	height: 12px;\n"
"	border-radius:5px;\n"
"}\n"
"QSlider::handle\n"
"{;\n"
"	background-color: rgb(0, 78, 21);\n"
"	border-radius:5px;\n"
"}\n"
"QSlider::sub-page{\n"
"	background-color: qlineargradient(spread:pad, x1:0.118, y1:1, x2:1, y2:1, stop:0.40448 rgba(23, 54, 8, 255), stop:1 rgba(48, 255, 101, 255))\n"
"}\n"
"QSlider::add-page{\n"
"	background-color: rgb(0, 26, 4);\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(Audio_Controller_Container);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        Audio = new QPushButton(Audio_Controller_Container);
        Audio->setObjectName("Audio");
        Audio->setCursor(QCursor(Qt::PointingHandCursor));
        Audio->setStyleSheet(QString::fromUtf8(""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Icons/Resoruces/Speaker.png"), QSize(), QIcon::Normal, QIcon::Off);
        Audio->setIcon(icon5);
        Audio->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(Audio);

        Audio_Slider = new QSlider(Audio_Controller_Container);
        Audio_Slider->setObjectName("Audio_Slider");
        Audio_Slider->setCursor(QCursor(Qt::PointingHandCursor));
        Audio_Slider->setValue(0);
        Audio_Slider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(Audio_Slider);

        currVolume = new QLabel(Audio_Controller_Container);
        currVolume->setObjectName("currVolume");

        horizontalLayout_2->addWidget(currVolume);


        horizontalLayout_3->addWidget(Audio_Controller_Container);


        horizontalLayout_11->addWidget(Play_Audio_backgward_BTN, 0, Qt::AlignLeft|Qt::AlignBottom);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer);

        Container_2 = new QFrame(Bottom_Buttons_2);
        Container_2->setObjectName("Container_2");
        Container_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 700 11pt \"Segoe UI\";\n"
"	padding:15px;\n"
"	color:purple;\n"
"}\n"
"QLabel\n"
"{\n"
"	color:white;\n"
"	font: 700 14pt \"Segoe UI\";\n"
"	margin-right:15px;\n"
"}\n"
"#Loop_Select_2\n"
"{\n"
"	color:red;\n"
"}"));
        Container_2->setFrameShape(QFrame::StyledPanel);
        Container_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(Container_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Video_length = new QLabel(Container_2);
        Video_length->setObjectName("Video_length");

        horizontalLayout->addWidget(Video_length);

        openFile = new QPushButton(Container_2);
        openFile->setObjectName("openFile");
        openFile->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(openFile);

        Btm_fullScreen = new QPushButton(Container_2);
        Btm_fullScreen->setObjectName("Btm_fullScreen");
        Btm_fullScreen->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Icons/Resoruces/fullScreen_Btm.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btm_fullScreen->setIcon(icon6);
        Btm_fullScreen->setIconSize(QSize(33, 33));

        horizontalLayout->addWidget(Btm_fullScreen);


        horizontalLayout_11->addWidget(Container_2);


        verticalLayout_6->addWidget(Bottom_Buttons_2);


        verticalLayout_5->addWidget(Bottom_Elems_parent_2);


        verticalLayout->addWidget(Bottom);

        QWidget::setTabOrder(Exit_4, Full_Restore_Screen_4);
        QWidget::setTabOrder(Full_Restore_Screen_4, MiniMize_4);
        QWidget::setTabOrder(MiniMize_4, openFile);
        QWidget::setTabOrder(openFile, Btm_fullScreen);
        QWidget::setTabOrder(Btm_fullScreen, Play_PAUSe);
        QWidget::setTabOrder(Play_PAUSe, BackWard);
        QWidget::setTabOrder(BackWard, Audio);
        QWidget::setTabOrder(Audio, Audio_Slider);
        QWidget::setTabOrder(Audio_Slider, Video_LEngth_2);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        About->setText(QString());
#if QT_CONFIG(tooltip)
        MiniMize_4->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p>miniMize</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        MiniMize_4->setText(QString());
#if QT_CONFIG(tooltip)
        Full_Restore_Screen_4->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p>fullScreen</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Full_Restore_Screen_4->setText(QString());
#if QT_CONFIG(tooltip)
        Exit_4->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p>Exit</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Exit_4->setText(QString());
#if QT_CONFIG(tooltip)
        Play_PAUSe->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p>Play</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Play_PAUSe->setText(QString());
#if QT_CONFIG(tooltip)
        BackWard->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p>reWind</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        BackWard->setText(QString());
#if QT_CONFIG(tooltip)
        Audio->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p>Mute</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Audio->setText(QString());
        currVolume->setText(QString());
        Video_length->setText(QString());
        openFile->setText(QCoreApplication::translate("Widget", "openFile", nullptr));
#if QT_CONFIG(tooltip)
        Btm_fullScreen->setToolTip(QCoreApplication::translate("Widget", "<html><head/><body><p>fullScreen</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Btm_fullScreen->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYER_H
