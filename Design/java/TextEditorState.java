package Design.java;
/**
 * 行为型模式-备忘录模式-Memento
 * 记录状态
 */
public class TextEditorState {
    private final String state;
    public String getState() {
        return state;
    }
    public TextEditorState(String state) {
        this.state = state;
    }
    
}
