from manim import *

class FlattenLinkedList(Scene):
    def construct(self):
        # Title
        title = Text("Flatten Multilevel Linked List - Merge Approach", font_size=32, color=YELLOW)
        title.to_edge(UP, buff=0.5)
        self.play(Write(title))
        self.wait(2)
        
        # Step 1: Create the original multilevel linked list
        self.show_original_structure()
        
        # Step 2: Show the merge process
        self.demonstrate_merge_process()
        
        # Step 3: Show final result
        self.show_final_result()
        
        self.wait(3)
    
    def show_original_structure(self):
        # Create explanation text
        explanation = Text("Original Multilevel Linked List", font_size=24, color=WHITE)
        explanation.move_to(UP * 2.5)
        self.play(Write(explanation))
        
        # Main list nodes: 1 -> 2 -> 3 -> 4
        self.main_nodes = []
        main_data = ["1", "2", "3", "4"]
        
        for i, data in enumerate(main_data):
            node = self.create_node(data, BLUE)
            node.move_to(LEFT * 4 + RIGHT * i * 2)
            self.main_nodes.append(node)
        
        # Create arrows between main nodes
        self.main_arrows = []
        for i in range(len(self.main_nodes) - 1):
            arrow = Arrow(
                self.main_nodes[i].get_right(),
                self.main_nodes[i + 1].get_left(),
                buff=0.1,
                color=WHITE
            )
            self.main_arrows.append(arrow)
        
        # Animate main list creation
        self.play(*[FadeIn(node) for node in self.main_nodes])
        self.play(*[Create(arrow) for arrow in self.main_arrows])
        
        # Child list under node 2: 7 -> 8 -> 11 -> 12
        self.child_nodes = []
        child_data = ["7", "8", "11", "12"]
        
        for i, data in enumerate(child_data):
            node = self.create_node(data, GREEN)
            node.move_to(LEFT * 2 + RIGHT * i * 1.5 + DOWN * 1.5)
            self.child_nodes.append(node)
        
        # Create arrows between child nodes
        self.child_arrows = []
        for i in range(len(self.child_nodes) - 1):
            arrow = Arrow(
                self.child_nodes[i].get_right(),
                self.child_nodes[i + 1].get_left(),
                buff=0.1,
                color=GREEN
            )
            self.child_arrows.append(arrow)
        
        # Child pointer from node 2
        self.child_pointer = Arrow(
            self.main_nodes[1].get_bottom(),
            self.child_nodes[0].get_top(),
            buff=0.1,
            color=YELLOW
        )
        
        # Animate child list creation
        self.play(*[FadeIn(node) for node in self.child_nodes])
        self.play(*[Create(arrow) for arrow in self.child_arrows])
        self.play(Create(self.child_pointer))
        
        # Sub-child list under node 8: 9 -> 10
        self.subchild_nodes = []
        subchild_data = ["9", "10"]
        
        for i, data in enumerate(subchild_data):
            node = self.create_node(data, RED)
            node.move_to(LEFT * 0.5 + RIGHT * i * 1.5 + DOWN * 3)
            self.subchild_nodes.append(node)
        
        # Create arrow between sub-child nodes
        self.subchild_arrow = Arrow(
            self.subchild_nodes[0].get_right(),
            self.subchild_nodes[1].get_left(),
            buff=0.1,
            color=RED
        )
        
        # Sub-child pointer from node 8
        self.subchild_pointer = Arrow(
            self.child_nodes[1].get_bottom(),
            self.subchild_nodes[0].get_top(),
            buff=0.1,
            color=ORANGE
        )
        
        # Animate sub-child list creation
        self.play(*[FadeIn(node) for node in self.subchild_nodes])
        self.play(Create(self.subchild_arrow))
        self.play(Create(self.subchild_pointer))
        
        self.wait(2)
        self.play(FadeOut(explanation))
    
    def demonstrate_merge_process(self):
        # Show merge process explanation
        merge_text = Text("Merge Process: Depth-First Traversal", font_size=24, color=YELLOW)
        merge_text.move_to(UP * 2.5)
        self.play(Write(merge_text))
        
        # Step 1: Highlight traversal to deepest level
        step1_text = Text("Step 1: Find deepest child (node 8 -> 9, 10)", font_size=20, color=WHITE)
        step1_text.move_to(UP * 2)
        self.play(Write(step1_text))
        
        # Highlight the path
        self.play(
            self.main_nodes[1].animate.set_color(YELLOW),
            self.child_nodes[1].animate.set_color(YELLOW),
            self.subchild_nodes[0].animate.set_color(YELLOW),
            self.subchild_nodes[1].animate.set_color(YELLOW)
        )
        self.wait(2)
        
        # Step 2: Merge sub-child into child list
        step2_text = Text("Step 2: Merge 9->10 into child list after 8", font_size=20, color=WHITE)
        step2_text.move_to(UP * 2)
        self.play(Transform(step1_text, step2_text))
        
        # Remove sub-child pointer
        self.play(FadeOut(self.subchild_pointer))
        
        # Move sub-child nodes to be inline with child list
        new_pos_9 = self.child_nodes[1].get_center() + RIGHT * 1.5
        new_pos_10 = new_pos_9 + RIGHT * 1.5
        
        self.play(
            self.subchild_nodes[0].animate.move_to(new_pos_9),
            self.subchild_nodes[1].animate.move_to(new_pos_10)
        )
        
        # Update arrows
        self.play(FadeOut(self.subchild_arrow))
        
        # New arrows: 8->9, 9->10, 10->11
        arrow_8_to_9 = Arrow(
            self.child_nodes[1].get_right(),
            self.subchild_nodes[0].get_left(),
            buff=0.1,
            color=GREEN
        )
        arrow_9_to_10 = Arrow(
            self.subchild_nodes[0].get_right(),
            self.subchild_nodes[1].get_left(),
            buff=0.1,
            color=GREEN
        )
        arrow_10_to_11 = Arrow(
            self.subchild_nodes[1].get_right(),
            self.child_nodes[2].get_left(),
            buff=0.1,
            color=GREEN
        )
        
        # Remove old arrow 8->11
        self.play(FadeOut(self.child_arrows[1]))
        
        # Add new arrows
        self.play(
            Create(arrow_8_to_9),
            Create(arrow_9_to_10),
            Create(arrow_10_to_11)
        )
        
        # Update child_arrows list
        self.child_arrows[1] = arrow_8_to_9
        self.child_arrows.insert(2, arrow_9_to_10)
        self.child_arrows.insert(3, arrow_10_to_11)
        
        self.wait(2)
        
        # Step 3: Merge child list into main list
        step3_text = Text("Step 3: Merge child list into main list after 2", font_size=20, color=WHITE)
        step3_text.move_to(UP * 2)
        self.play(Transform(step1_text, step3_text))
        
        # Remove child pointer
        self.play(FadeOut(self.child_pointer))
        
        # Move all child and sub-child nodes to main level
        all_child_nodes = self.child_nodes + self.subchild_nodes
        
        # Calculate new positions
        base_y = self.main_nodes[0].get_center()[1]
        start_x = self.main_nodes[1].get_center()[0] + 2
        
        new_positions = []
        for i, node in enumerate(all_child_nodes):
            new_pos = [start_x + i * 1.5, base_y, 0]
            new_positions.append(new_pos)
        
        # Animate movement
        animations = []
        for node, pos in zip(all_child_nodes, new_positions):
            animations.append(node.animate.move_to(pos))
        
        self.play(*animations)
        
        # Update main list arrows
        # Remove old arrow 2->3
        self.play(FadeOut(self.main_arrows[1]))
        
        # Create new arrows
        arrow_2_to_7 = Arrow(
            self.main_nodes[1].get_right(),
            self.child_nodes[0].get_left(),
            buff=0.1,
            color=BLUE
        )
        
        arrow_12_to_3 = Arrow(
            self.child_nodes[3].get_right(),
            self.main_nodes[2].get_left(),
            buff=0.1,
            color=BLUE
        )
        
        self.play(Create(arrow_2_to_7), Create(arrow_12_to_3))
        
        # Update colors to show unified list
        self.play(
            *[node.animate.set_color(BLUE) for node in all_child_nodes],
            *[arrow.animate.set_color(BLUE) for arrow in self.child_arrows]
        )
        
        self.wait(2)
        self.play(FadeOut(step1_text), FadeOut(merge_text))
    
    def show_final_result(self):
        # Final result text
        final_text = Text("Final Flattened Linked List", font_size=24, color=GREEN)
        final_text.move_to(UP * 2.5)
        self.play(Write(final_text))
        
        # Show the complete sequence
        sequence_text = Text("1 → 2 → 7 → 8 → 9 → 10 → 11 → 12 → 3 → 4", font_size=20, color=WHITE)
        sequence_text.move_to(DOWN * 2.5)
        self.play(Write(sequence_text))
        
        # Highlight the final path
        all_nodes = (self.main_nodes[:2] + self.child_nodes + self.subchild_nodes + 
                    self.main_nodes[2:])
        
        # Flash animation to show the complete path
        for node in all_nodes:
            self.play(node.animate.set_color(YELLOW), run_time=0.3)
            self.play(node.animate.set_color(BLUE), run_time=0.3)
        
        # Algorithm complexity
        complexity_text = Text("Time: O(n), Space: O(d) where d is max depth", 
                             font_size=18, color=GRAY)
        complexity_text.move_to(DOWN * 3.2)
        self.play(Write(complexity_text))
        
        self.wait(3)
    
    def create_node(self, value, color):
        """Create a linked list node with value and color"""
        circle = Circle(radius=0.4, color=color, fill_opacity=0.3)
        text = Text(str(value), font_size=20, color=WHITE)
        text.move_to(circle.get_center())
        return VGroup(circle, text)
