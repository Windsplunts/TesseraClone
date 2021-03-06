#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QtGui>
#include <QtWidgets>
#include "Tile.h"
#include "TesseraParameters.h"

class ControlPanel : public QWidget {
    Q_OBJECT
public:
    ControlPanel	(QWidget *parent=0, Qt::WindowFlags f=0);
    ControlPanel    (QMap<QRgb,Tile>, QWidget *parent=0, Qt::WindowFlags f=0);
    void			resetImage          ();

public slots:
    void			expandPanels		();

    // BC/HSL slots
    void			resetBrightness		();
    void			resetContrast		();
    void			resetHue            ();
    void			resetSaturation		();
    void			resetLightness		();
    void			changeBrightness	(int);
    void			changeContrast		(int);
    void			changeHue           (int);
    void			changeSaturation	(int);
    void			changeLightness		(int);
    void			revertOriginal		();
    void			resetInputControls	();
    void			resetControls		();
    void            setTileMap (QMap<QRgb, Tile>);

protected:
    void			createPanelTree		();
    QGroupBox*		createGroupInput	();
    QGroupBox*		createGroupSize		();
    QGroupBox*		createGroupRender	();
    QGroupBox*		createGroupTile		();
    QGroupBox*		createGroupGrout	();

    int		updateInputImage (TesseraParameters::ColorMode mode);
private:
    QVBoxLayout                 *m_cpBox;
    QTreeWidget                 *m_tree;
    QVector<QGroupBox*>         m_group;
    QVector<QTreeWidgetItem*>   m_item;
    QVector<QTreeWidgetItem*>   m_header;
    QVector<QPushButton*>       m_button;

    // widgets for input groupbox
    QRadioButton    *m_radioIn[2];
    QPushButton     *m_buttonIn[5];
    QSlider         *m_sliderIn[5];
    QLabel          *m_labelIn [5];
    QStackedWidget	*m_stackWidgetIn;

    // other variables
    QMap<QRgb, Tile>    tileMap;
    QImage		m_image; // image that is used as original
                 // when switching between RGB and HSL
                 // color modes
                 //
};

#endif	// CONTROLPANEL_H
