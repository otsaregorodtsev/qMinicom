#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include "asyncserialport.h"

#include <QDialog>

class MainWindow;

namespace Ui {
class PreferencesDialog;
}

class PreferencesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PreferencesDialog(MainWindow *parent);
    ~PreferencesDialog();

signals:
    void openSerialPort(const QString &pn, qint32 br);
    void openLocalShell();

public slots:
    void open();
    void accept();

private slots:
    void pickUpFont(const QString &name);
    void pickUpFontSize(int val);
    void pickUpTabSize(int val);
    void pickUpPortSelection();

private:
    void readSettings();
    void writeSettings();
    void plainTextUpdateDemo();
    int pixelsFromSpaces(int spaceCount);

    Ui::PreferencesDialog *ui;

    MainWindow *m_mainWindow;
    int m_textShade;
    int m_bgShade;
    QString m_serialPortName;
};

#endif // PREFERENCESDIALOG_H
