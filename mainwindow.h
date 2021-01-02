#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QTextCharFormat>
#include <QtGui>
#include <QtCore>
#include <QAction>
#include <QMenu>
#include <QUrl>
#include <QIcon>
#include <QFileInfo>
#include <QFont>
#include <QFontDatabase>
#include <QColor>
#include <QColorDialog>
#include <QTextCursor>
#include <QTextCharFormat>
#include <QSettings>
#include <QStringList>
#include <QDateTime>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_As_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionZoom_In_triggered();

    void on_actionZoom_Out_triggered();

    void on_actionClear_All_triggered();

    void on_actionSelect_All_triggered();

    void on_actionBold_triggered();

    void on_actionItalic_triggered();

    void on_actionUnderline_triggered();

    void on_actionDisc_triggered();

    void on_actionCircle_triggered();

    void on_actionSqure_triggered();

    void on_actionArabic_triggered();

    void on_actionUppercase_Normal_triggered();

    void on_actionLowercase_Roman_triggered();

    void on_actionColor_triggered();

private:
    Ui::MainWindow *ui;
   QString currentFile= "";
   void selectionSync(const QTextCharFormat &format);
};
#endif // MAINWINDOW_H
