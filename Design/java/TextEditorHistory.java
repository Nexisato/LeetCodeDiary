package Design.java;
/**
 * 行为型模式-备忘录模式-Caretaker
 * 负责记录 TextEditorState 的历史
 */

import java.util.ArrayList;
import java.util.List;

public class TextEditorHistory {
    private List<TextEditorState> states = new ArrayList<>();

    public void push(TextEditorState state) {
        states.add(state);
    }
    
    public TextEditorState pop() {
        int lastIndex = states.size() - 1;
        return states.remove(lastIndex);
    }
}
