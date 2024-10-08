#include <QApplication>
#include <QTabWidget>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QTabWidget *TabWidget = new QTabWidget;
    QWidget *LeaderTab = new QWidget;
    QLabel *LeaderLabel = new QLabel("隊長:郭至峻\n組員1:郭至峻\n組員2:陳彥妤\n組員3");
    LeaderLabel->setStyleSheet("color: blue;");
    QVBoxLayout *LeaderLayout = new QVBoxLayout;
    LeaderLayout->addWidget(LeaderLabel);
    LeaderTab->setLayout(LeaderLayout);

   QWidget *member2Tab = new QWidget;
    QLabel *member2Label = new QLabel("這是組員2頁面");
    QPushButton *styleButton = new QPushButton("Front select");
    QVBoxLayout *member2Layout = new QVBoxLayout;
    member2Layout->addWidget(member2Label);
    member2Layout->addWidget(styleButton);
    member2Tab->setLayout(member2Layout);


    QObject::connect(styleButton, &QPushButton::clicked, [=]() {
        bool ok;
        QFont font = QFontDialog::getFont(&ok, leaderLabel->font(), nullptr, "選擇字體");
        if (ok) {
            leaderLabel->setFont(font);
        }
    });
    TabWidget->addTab(LeaderTab, "隊長");
    TabWidget->addTab(member1Tab, "組員1");
    TabWidget->addTab(member1Tab, "組員2");


    TabWidget->setWindowTitle("example");
    TabWidget->resize(400, 300);
    TabWidget->show();
    return app.exec();
}
