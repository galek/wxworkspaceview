/**
 * @author Thijs Kruithof, Walter Tamboer
 */

#pragma once

#include "wxWorkspaceItem.h"
#include <vector>

/**
 * This is the base class for nodes which can be drawn on the workspace.
 * Nodes should be created through the WorkspaceFactory.
 */
class WorkspaceNode: public WorkspaceItem
{
public:
	/**
	 * Initializes a new instance of this class.
	 */
	WorkspaceNode(const wxRect& Area, int InputCount, int OutputCount, const wxString& Title);
public:
	/**
	 * Returns true if this items hits with an connector.
	 */
	virtual bool HasHitWithConnector(const wxPoint& Position, ConnectorInfo* Result);
public:
	/**
	 * Gets the area of a specific port.
	 */
	wxRect GetPortArea(int PortIndex, bool Output) const;
protected:
	struct PortInfo
	{
		wxString Label;
		float LabelAngle;
		wxRealPoint LabelDirection; 
		wxRect ConnectorArea;
	};
	/**
	 * The output connector list.
	 */
	std::vector<PortInfo> OutputList;
	/**
	 * The input connector list.
	 */
	std::vector<PortInfo> InputList;
	/**
	 * The title of this node.
	 */
	wxString Title;
};