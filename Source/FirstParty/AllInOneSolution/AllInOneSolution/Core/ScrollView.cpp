#include "ScrollView.hpp"

ScrollView::ScrollView(const sf::Vector2u& levelsize, const sf::Vector2u& viewsize)
	: m_viewSize(viewsize), m_levelSize(levelsize)
{
}

void ScrollView::adjustView(const sf::Vector2f& scrollvec, sf::RenderWindow& window)
{
	sf::View view = window.getView();
	sf::Vector2f center = scrollvec;
	
	if(m_levelSize.x < m_viewSize.x)
	{
		center.x = m_viewSize.x / 2.0f;
	}
	else
	{
		if(center.x < (m_viewSize.x / 2))
		{
			center.x = m_viewSize.x / 2.0f;
		}
		else if(center.x > m_levelSize.x - m_viewSize.x / 2.0f)
		{
			center.x = m_levelSize.x - m_viewSize.x / 2.0f;
		}
	}

	if(m_levelSize.y < m_viewSize.y)
	{
		center.y = m_viewSize.y / 2.0f;
	}
	else
	{
		if(center.y < (m_viewSize.y / 2))
		{
			center.y = m_viewSize.y / 2.0f;
		}
		else if(center.y > m_levelSize.y - m_viewSize.y / 2.0f)
		{
			center.y = m_levelSize.y - m_viewSize.y / 2.0f;
		}
	}

	view.setCenter(center);
	window.setView(view);
}