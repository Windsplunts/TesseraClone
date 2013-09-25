#include <QtWidgets>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){

    m_createActions();
    m_createMenus();
    m_createStatusBar();
    m_createToolBars();
}

void MainWindow::closeEvent(QCloseEvent *event){

}

void MainWindow::m_createActions(){
    // File Menu
    a_newProject = new QAction(QIcon(":/icons/file-new.png"),tr("&New"),this);
    a_newProject->setShortcut((QKeySequence::New));
    a_newProject->setStatusTip(tr("Create a new file"));
    a_openExample;
    a_loadProject;

    a_saveProject;
    a_saveAsProject;

    a_savePalette;
    a_loadPalette;

    a_exportPallet;
    a_quit;
}

void MainWindow::m_createMenus(){
    // File Menu
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(a_newProject);

    // Edit Menu
    editMenu = menuBar()->addMenu(tr("$Edit"));

    // View Menu
    viewMenu = menuBar()->addMenu(tr("$View"));
}

void MainWindow::m_createStatusBar(){
}

void MainWindow::m_createToolBars(){
}