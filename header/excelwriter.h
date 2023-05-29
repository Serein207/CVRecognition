#ifndef EXCELWRITER_H
#define EXCELWRITER_H

#include <QAxWidget>

class ExcelWriter {
public:
	void newExcel();
	void appendSheet(const QString& sheetName, int cnt);
	void saveExcel();
	void freeExcel();
	void writeData(QVector<QVector<QString>>& contents);
	ExcelWriter(const QString& filename, QVector<QVector<QString>>& contents);

private:
	QAxObject* pApplication;
	QAxObject* pWorkBooks;
	QAxObject* pWorkBook;
	QAxObject* pSheets;
	QAxObject* pSheet;
	QString fileName;
	void setCellValue(int row, int column, const QString& value);
};

#endif // EXCELWRITER_H
