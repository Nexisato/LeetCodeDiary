package Design.java;

/**
 * 行为型模式-备忘录模式
 * Originator: 原发器，即 TextEditor
 * Memento: 备忘录, 即 TextEditorState
 * Caretaker: 管理者, 即 TextEditorHistory
 */
public class TextEditor {
    private StringBuilder content = new StringBuilder();

    public void add(String text) {
        content.append(text);
    }

    public void add(char c) {
        content.append(c);
    }

    public void delete() {
        if (content.length() > 0) {
            content.deleteCharAt(content.length() - 1);
        }
    }

    // 获取状态
    public String getState() {
        return content.toString();
    }

    // 恢复状态
    public void setState(String state) {
        this.content.delete(0, this.content.length());
        this.content.append(state);
    }

    // method1: 创建备忘录
    public TextEditorState createState() {
        return new TextEditorState(content.toString());
    }

    // method2: 恢复备忘录
    public void restore(TextEditorState state) {
        setState(state.getState());
    }

}


