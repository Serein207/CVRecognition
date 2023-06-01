#include "excelwriter.h"
#include <QFile>
#include <QDir>
#include <QAxObject>


ExcelWriter::ExcelWriter(const QString& filename, QVector<QVector<QString>>& contents)
    : fileName(filename)
{
    newExcel();
    writeData(contents);
    saveExcel();
    freeExcel();
}

void ExcelWriter::newExcel() {
    pApplication = new QAxObject("Excel.Application");
    if (pApplication == nullptr) {
        qWarning("pApplication\n");
        return;
    }
    pApplication->dynamicCall("SetVisible(bool)", false);
    pApplication->setProperty("DisplayAlerts", false);
    pWorkBooks = pApplication->querySubObject("Workbooks");
    QFile file(fileName);
    pWorkBooks->dynamicCall("Add");
    if (pWorkBooks == nullptr) {
        return;
    }
    pWorkBook = pApplication->querySubObject("ActiveWorkBook");
    pSheets = pWorkBook->querySubObject("Sheets");
    pSheet = pSheets->querySubObject("Item(int)", 1);
}

void ExcelWriter::appendSheet(const QString& sheetName, int cnt)
{
    QAxObject* pLastSheet = pSheets->querySubObject("Item(int)", cnt);
    pSheets->querySubObject("Add(QVariant)", pLastSheet->asVariant());
    pSheet = pSheets->querySubObject("Item(int)", cnt);
    pLastSheet->dynamicCall("Move(QVariant)", pSheet->asVariant());
    pSheet->setProperty("Name", sheetName);
}

void ExcelWriter::writeData(QVector<QVector<QString>>& contents) {
    setCellValue(1, 1, QStringLiteral("简历文件名"));
    setCellValue(1, 2, QStringLiteral("姓名"));
    setCellValue(1, 3, QStringLiteral("年龄"));
    setCellValue(1, 4, QStringLiteral("最高学历"));
    setCellValue(1, 5, QStringLiteral("毕业院校"));
    setCellValue(1, 6, QStringLiteral("工作年限"));
    setCellValue(1, 7, QStringLiteral("匹配岗位"));
    for (int row = 2; row < contents.size() + 2; ++row) {
        for (int col = 1; col < 8; ++col) {
            setCellValue(row, col, contents[row - 2][col - 1]);
        }
    }
}

void ExcelWriter::setCellValue(int row, int column, const QString& value) {
    QAxObject* pRange = pSheet->querySubObject("Cells(int,int)", row, column);
    pRange->dynamicCall("Value", value);
}

void ExcelWriter::saveExcel()
{
    pWorkBook->dynamicCall("SaveAs(const QString &)", QDir::toNativeSeparators(fileName));
}

void ExcelWriter::freeExcel()
{
    if (pApplication != nullptr) {
        pApplication->dynamicCall("Quit()");
        delete pApplication;
        pApplication = nullptr;
    }
}