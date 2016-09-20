import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.1
import com.dreamdev.QtAdMobBanner 1.0
import com.dreamdev.QtAdMobInterstitial 1.0

Window {
    id: mainWindow
    visible: true
    onWidthChanged: {
        banner.x = (mainWindow.width - banner.width) / 2
    }

    AdMobBanner
    {
        id: banner

        Component.onCompleted: {
            banner.unitId = "ca-app-pub-7485900711629006/8288667458"
            banner.size = AdMobBanner.Banner
            banner.visible = true
        }

        onLoaded: {
            bannerButton.enabled = true
            bannerButton.text = (banner.visible ? qsTr("Hide") : qsTr("Show"))
            banner.x = (mainWindow.width - banner.width) / 2
        }
    }

    AdMobInterstitial
    {
        id: intertitial

        Component.onCompleted: {
            intertitial.unitId = "ca-app-pub-7485900711629006/9462519453"
        }

        onClosed: {
            intertitial.unitId = "ca-app-pub-7485900711629006/9462519453"
        }

        onLoaded: {
            interstitialButton.enabled = true
            interstitialButton.text = qsTr("Show")
        }

        onLoading: {
            interstitialButton.enabled = false
            interstitialButton.text = qsTr("Loading...")
        }
    }

    ColumnLayout
    {
        spacing: 50
        anchors.fill: parent

        Button {
            id: bannerButton
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Loading...")
            width: 200
            height: 60
            enabled: false

            onClicked: {
                banner.visible = !banner.visible
                bannerButton.text = (banner.visible ? qsTr("Hide") : qsTr("Show"))
            }
        } // Button

        Button {
            id: interstitialButton
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Loading...")
            width: 200
            height: 60
            enabled: false

            onClicked: {
                if (intertitial.isLoaded)
                {
                    intertitial.visible = true
                }
            }
        } // Button
    } // ColumnLayout
}

