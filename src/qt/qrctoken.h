#ifndef ERCTOKEN_H
#define ERCTOKEN_H

#include <qt/sendtokenpage.h>
#include <qt/receivetokenpage.h>
#include <qt/addtokenpage.h>

#include <QWidget>
#include <QModelIndex>
#include <QAbstractItemModel>

class TokenViewDelegate;
class WalletModel;
class ClientModel;
class TokenTransactionView;
class PlatformStyle;
class QMenu;

namespace Ui {
class ERCToken;
}

class ERCToken : public QWidget
{
    Q_OBJECT

public:
    explicit ERCToken(const PlatformStyle *platformStyle, QWidget *parent = 0);
    ~ERCToken();

    void setModel(WalletModel *_model);
    void setClientModel(ClientModel *clientModel);

Q_SIGNALS:

public Q_SLOTS:
    void on_goToSendTokenPage();
    void on_goToReceiveTokenPage();
    void on_goToAddTokenPage();
    void on_currentTokenChanged(QModelIndex index);
    void on_dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles = QVector<int>());
    void on_currentChanged(QModelIndex current, QModelIndex previous);
    void on_rowsInserted(QModelIndex index, int first, int last);
    void contextualMenu(const QPoint &);
    void copyTokenAddress();
    void copyTokenBalance();
    void copyTokenName();
    void copySenderAddress();
    void removeToken();

private:
    Ui::ERCToken *ui;
    SendTokenPage* m_sendTokenPage;
    ReceiveTokenPage* m_receiveTokenPage;
    AddTokenPage* m_addTokenPage;
    WalletModel* m_model;
    ClientModel* m_clientModel;
    QAbstractItemModel* m_tokenModel;
    TokenViewDelegate* m_tokenDelegate;
    QAction *m_sendAction;
    QAction *m_receiveAction;
    QAction *m_addTokenAction;
    QString m_selectedTokenHash;
    TokenTransactionView *m_tokenTransactionView;
    const PlatformStyle *m_platformStyle;
    QMenu *contextMenu;
};

#endif // ERCTOKEN_H
