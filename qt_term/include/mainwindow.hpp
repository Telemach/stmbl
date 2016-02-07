/*
LICENSE

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.

FEEDBACK & QUESTIONS

For feedback and questions about stmbl please e-mail one of the authors named in
the AUTHORS file.
*/

#pragma once

#include <ui_mainwindow.h>
#include <QMainWindow>
#include <QTimer>
#include <QString>
#include <QVector>

#include <vector>

class MainWindow : public QMainWindow, private Ui::MainWindow
{
	Q_OBJECT
	
	private:
		QVector<QString> history;
		int historypos;

		QTimer* timer;

	public:
		explicit MainWindow(QWidget *parent = 0);
    
    protected:
        bool eventFilter(QObject* obj, QEvent *event) override;

	signals:
		void timeoutEvent();

	public slots:
		void on_actionReset_triggered();
		void on_actionResetMatrix_triggered();
        void pollTimerEvent();
	private slots:
		void on_actionExit_triggered();
};
