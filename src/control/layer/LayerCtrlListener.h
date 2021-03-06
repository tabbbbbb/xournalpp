/*
 * Xournal++
 *
 * Layer Controller listener
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <XournalType.h>

class LayerController;

class LayerCtrlListener
{
public:
	LayerCtrlListener();
	virtual ~LayerCtrlListener();

public:
	void registerListener(LayerController* handler);
	void unregisterListener();

	virtual void rebuildLayerMenu();
	virtual void layerVisibilityChanged();

private:
	XOJ_TYPE_ATTRIB;

	LayerController* handler;
};
