#include "stdafx.h"

// General
#include "UIInput.h"

// Additional
#include "UIMgr.h"

UIInput::UIInput() : base()
{
	inputStringMaxLenght = 15;
	inputMode = InputMode::MODE_ANY;

	m_IsTextEnable = true;
	m_Text = "";
}

void UIInput::Init(cvec2 _position, cvec2 _size, InputMode _inputMode)
{
	m_TextOffset = vec2(6, _size.y / 2);
	m_TextAlignW = TextAlignW::TEXT_ALIGNW_LEFT;
	m_TextAlignH = TextAlignH::TEXT_ALIGNH_CENTER;

	inputMode = _inputMode;

	auto inputTexture = _Render->TexturesMgr()->Add("images/ui/buttons/listbox_char.png");

	base::Init(_position, _size, new Image(inputTexture));
}

void UIInput::OnRenderUI()
{
	base::OnRenderUI();

	if (_UIMgr->GetFocus() == this)
		_Render->RenderRectangleOutline(GetPosition() + vec2(2, 2), m_Size - vec2(4, 4), COLOR_WHITE);
}

bool UIInput::OnMouseButtonPressed(int _button, int _mods, cvec2 _mousePos)
{
	if (_UIMgr->GetFocus() == this)
		_UIMgr->SetFocus(nullptr);
	else
		_UIMgr->SetFocus(this);

	return true;
}

bool UIInput::OnKeyboardPressed(int _key, int _scancode, int _mods)
{
	if (_UIMgr->GetFocus() != this)
		return false;

	if (_key == OW_KEY_BACKSPACE && m_Text.length() > 0)
	{
		m_Text.pop_back();

		return true;
	}

	return false;
}

bool UIInput::OnCharInput(uint32 _char)
{
	if (_UIMgr->GetFocus() != this)
		return false;

	if (m_Text.length() > inputStringMaxLenght - 1)
		return true;

	if (inputMode == MODE_CHARACTERS && (_char < 'a' || _char > 'z') && (_char < 'A' || _char > 'Z'))
		return true;

	if (inputMode == MODE_NUMBERS && (_char < '0' || _char > '9'))
		return true;

	m_Text += char(_char);

	return true;
}