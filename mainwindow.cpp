#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
     currentFile.clear();
     ui->textEdit->setText(QString());
}

void MainWindow::on_actionOpen_triggered()
{
  QString fileName = QFileDialog::getOpenFileName(this,"Open the file");

  QFile file(fileName);
  currentFile = fileName;
  if(!file.open(QIODevice::ReadOnly | QFile :: Text))
  {
    QMessageBox :: warning(this,"warning","Cannot Open File :" + file.errorString());
    return;
  }

 setWindowTitle(fileName);
 QTextStream in(&file);
 QString text = in.readAll();
 ui->textEdit->setText(text);
 file.close();
}

void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog :: getSaveFileName(this, "Save as");
    QFile file(fileName);
    if(!file.open(QFile ::WriteOnly | QFile :: Text))
    {
        QMessageBox :: warning(this, "warning","cannot save this file : " +file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<< text;
    file.close();


}



void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer Name");
    QPrintDialog pDialog(&printer,this);
    if(pDialog.exec() == QDialog :: Rejected)
    {
        QMessageBox :: warning(this,"warning","Cannot Access printer");
        return;
    }
    ui->textEdit->print(&printer);
}

void MainWindow::on_actionExit_triggered()
{
    QApplication :: quit();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}



void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionZoom_In_triggered()
{
    ui->textEdit->zoomIn();
}



void MainWindow::on_actionZoom_Out_triggered()
{
    ui->textEdit->zoomOut();
}

void MainWindow::on_actionClear_All_triggered()
{
    ui->textEdit->clear();
}



void MainWindow::on_actionSelect_All_triggered()
{
    ui->textEdit->selectAll();
}


void MainWindow::on_actionBold_triggered()
{
    QTextCharFormat syn;
    syn.setFontWeight(ui->actionBold->isChecked()? QFont::Bold : QFont :: Normal);
   selectionSync (syn);
}


void MainWindow::on_actionItalic_triggered()
{
   QTextCharFormat syn;
   syn.setFontWeight(ui->actionItalic->isChecked());
   selectionSync(syn);

}

void MainWindow::on_actionUnderline_triggered()
{
    QTextCharFormat syn;
    syn.setFontUnderline(ui->actionUnderline->isChecked());
    selectionSync(syn);
}

void MainWindow::on_actionDisc_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextListFormat::Style lStyle = QTextListFormat::ListDisc;

    cursor.beginEditBlock();

    QTextBlockFormat bFormat = cursor.blockFormat();
    QTextListFormat liFormat;

    if(cursor.currentList())
    {
        liFormat = cursor.currentList()->format();
    }
    else
    {
        liFormat.setIndent(bFormat.indent() + 1);
        bFormat.setIndent(0);
        cursor.setBlockFormat(bFormat);
    }

    liFormat.setStyle(lStyle);
    cursor.createList(liFormat);
    cursor.endEditBlock();
}


void MainWindow ::selectionSync(const QTextCharFormat &format)
{
    QTextCursor cursor = ui->textEdit->textCursor();
    if(!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(format);
    ui->textEdit->mergeCurrentCharFormat(format);
}



void MainWindow::on_actionCircle_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextListFormat::Style lStyle = QTextListFormat::ListCircle;

    cursor.beginEditBlock();

    QTextBlockFormat bFormat = cursor.blockFormat();
    QTextListFormat liFormat;

    if(cursor.currentList())
    {
        liFormat = cursor.currentList()->format();
    }
    else
    {
        liFormat.setIndent(bFormat.indent() + 1);
        bFormat.setIndent(0);
        cursor.setBlockFormat(bFormat);
    }

    liFormat.setStyle(lStyle);
    cursor.createList(liFormat);
    cursor.endEditBlock();
}





void MainWindow::on_actionSqure_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextListFormat::Style lStyle = QTextListFormat::ListSquare;

    cursor.beginEditBlock();

    QTextBlockFormat bFormat = cursor.blockFormat();
    QTextListFormat liFormat;

    if(cursor.currentList())
    {
        liFormat = cursor.currentList()->format();
    }
    else
    {
        liFormat.setIndent(bFormat.indent() + 1);
        bFormat.setIndent(0);
        cursor.setBlockFormat(bFormat);
    }

    liFormat.setStyle(lStyle);
    cursor.createList(liFormat);
    cursor.endEditBlock();
}


void MainWindow::on_actionArabic_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextListFormat::Style lStyle = QTextListFormat::ListDecimal;

    cursor.beginEditBlock();

    QTextBlockFormat bFormat = cursor.blockFormat();
    QTextListFormat liFormat;

    if(cursor.currentList())
    {
        liFormat = cursor.currentList()->format();
    }
    else
    {
        liFormat.setIndent(bFormat.indent() + 1);
        bFormat.setIndent(0);
        cursor.setBlockFormat(bFormat);
    }

    liFormat.setStyle(lStyle);
    cursor.createList(liFormat);
    cursor.endEditBlock();

}






void MainWindow::on_actionUppercase_Normal_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextListFormat::Style lStyle = QTextListFormat::ListUpperRoman;

    cursor.beginEditBlock();

    QTextBlockFormat bFormat = cursor.blockFormat();
    QTextListFormat liFormat;

    if(cursor.currentList())
    {
        liFormat = cursor.currentList()->format();
    }
    else
    {
        liFormat.setIndent(bFormat.indent() + 1);
        bFormat.setIndent(0);
        cursor.setBlockFormat(bFormat);
    }

    liFormat.setStyle(lStyle);
    cursor.createList(liFormat);
    cursor.endEditBlock();
}



void MainWindow::on_actionLowercase_Roman_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextListFormat::Style lStyle = QTextListFormat::ListLowerRoman;

    cursor.beginEditBlock();

    QTextBlockFormat bFormat = cursor.blockFormat();
    QTextListFormat liFormat;

    if(cursor.currentList())
    {
        liFormat = cursor.currentList()->format();
    }
    else
    {
        liFormat.setIndent(bFormat.indent() + 1);
        bFormat.setIndent(0);
        cursor.setBlockFormat(bFormat);
    }

    liFormat.setStyle(lStyle);
    cursor.createList(liFormat);
    cursor.endEditBlock();
}



void MainWindow::on_actionColor_triggered()
{
    QColor textColor = QColorDialog::getColor();
    ui->textEdit->setTextColor(textColor);
}
