#include "FQLogger.h"

FQLogger::Logger::Logger(QString logName, QString path) : FLogger::Logger(logName.toStdString(), path.toStdString())
{
}

FQLogger::Logger::~Logger()
{
    this->FLogger::Logger::~Logger();
}

void FQLogger::Logger::write(QString text)
{
    this->FLogger::Logger::write(text.toStdString());
}

void FQLogger::Logger::error(QString text)
{
    this->FLogger::Logger::error(text.toStdString());
}

void FQLogger::Logger::fatalError(QString text)
{
    this->FLogger::Logger::fatalError(text.toStdString());
}

void FQLogger::Logger::warning(QString text)
{
    this->FLogger::Logger::warning(text.toStdString());
}

void FQLogger::Logger::info(QString text)
{
    this->FLogger::Logger::info(text.toStdString());
}

void FQLogger::Logger::write(QString text, int line, QString codeFile, QString func)
{
    this->FLogger::Logger::write(text.toStdString(), line, codeFile.toStdString(), func.toStdString());
}

void FQLogger::Logger::error(QString text, int line, QString codeFile, QString func)
{
    this->FLogger::Logger::error(text.toStdString(), line, codeFile.toStdString(), func.toStdString());
}

void FQLogger::Logger::fatalError(QString text, int line, QString codeFile, QString func)
{
    this->FLogger::Logger::fatalError(text.toStdString(), line, codeFile.toStdString(), func.toStdString());
}

void FQLogger::Logger::warning(QString text, int line, QString codeFile, QString func)
{
    this->FLogger::Logger::warning(text.toStdString(), line, codeFile.toStdString(), func.toStdString());
}

void FQLogger::Logger::info(QString text, int line, QString codeFile, QString func)
{
    this->FLogger::Logger::info(text.toStdString(), line, codeFile.toStdString(), func.toStdString());
}

bool FQLogger::Logger::setStartText(QString text)
{
    return this->FLogger::Logger::setStartText(text.toStdString());
}

void FQLogger::Logger::setEndText(QString text)
{
    this->FLogger::Logger::setEndText(text.toStdString());
}
