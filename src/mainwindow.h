#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebView>
#include <rabiche.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Q_INVOKABLE QMap<QString, QVariant> newHtmlTweets();
    Q_INVOKABLE QMap<QString, QVariant> newOfflineHtmlTweets();

private slots:
    void onNewTweets(TweetsMap tweets);
    void onNewOfflineTweets(TweetsMap tweets);
    void onLinkClicked(const QUrl &url);
    void loadFinished(bool b);
    void onJavaScriptWindowObjectCleared();

private:
    bool firstTime_;
    QThread* thread_;
    Twitter* twitter_;
    QWebView* webView_;
    QMap<QString, QVariant> htmlTweets_;
    QMap<QString, QVariant> newHtmlTweets_;
    QMap<QString, QVariant> newOfflineHtmlTweets_;
    int page_;
    int pageSize_;

    void init();
    QMap<QString, QVariant> twittsToHtml(TweetsMap twitts);
    QString htmlPagination();
    void goToPage(int page);

};

#endif // MAINWINDOW_H
