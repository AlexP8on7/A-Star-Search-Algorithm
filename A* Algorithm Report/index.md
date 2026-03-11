<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>C++ Project A* Search Algorithm
</title>
    <style>
        body {
            margin: 0;
            font-family: Arial, sans-serif;
        }
        .container {
            display: flex;
        }
        .navbar {
            width: 200px;
            background-color: #333;
            color: white;
            padding: 15px;
            height: 120vh;
              }
        .navbar a {
            display: block;
            color: white;
            text-decoration: none;
            padding: 10px 0;
        }
        .navbar a:hover {
            background-color: #575757;
        }
        .content {
            margin-left: 220px;
            padding: 20px;
        }
        h1, h2 {
            border-bottom: 2px solid #ddd;
            padding-bottom: 5px;
        }
    </style>
</head>
<body>
    <div class="container">
        
        <div class="navbar">
            <h3>Navigation</h3>
            <a href="#introduction">Introduction</a>
            <a href="#project-setup">Project Set-Up</a>
            <a href="#template-code">Template Code</a>
            <a href="#simulation">Simulation</a>
            <a href="#synthesis">Synthesis</a>
            <a href="#vga-design">My VGA Design Edit</a>
            <a href="#code-adaptation">Code Adaptation</a>
            <a href="#final-demonstration">Final Demonstration</a>
        </div>

        <div class="content">
            <h1 id="introduction">Introduction</h1>
            <p>Welcome to my FPGA VGA Driver Project blog, where I will be presenting my learnings from the System on Chip Design and Verification project. I will be discussing the use of the Basys3 board and how I was able to implement certain methods to display my design on a laboratory monitor.</p>
            <div style="display: flex; gap: 20px; justify-content: center;">
                <div style="width: 50%; height: 400px; overflow: hidden;">
                    <img src="https://raw.githubusercontent.com/AlexP8on7/FPGA_VGA_SOC_Project/main/images/Bayas3.jpg" alt="Simulation Screenshot 1" style="width: 100%; transform: rotate(90deg); object-fit: cover; object-position: center;">
                </div>
            </div>

            <h2 id="project-setup">Project Set-Up</h2>
            <p>My project, titled VGAColourCycle, is implemented using Vivado with the target part xc7a35tcpg236-1 (Artix-7 FPGA). The top module is VGATop, coded in Verilog with a mixed simulator setup. Synthesis and implementation were successfully completed, including the generation of the bitstream file, with some warnings (13 during synthesis and 5 during implementation). The design had no timing violations.</p>

            <h2 id="template-code">Template Code</h2>
            <p>The Verilog code templates, ColourCycle and ColourStripes, I used to gain understanding of the programming implemented in this project, used distinct RGB color generation modules designed to interface with a VGA display. I found that the ColourCycle module conatined a state machine that cycles through specific colors (black, red, yellow, green, cyan, blue, magenta, and white) at specific time intervals based on a counter. The output RGB values were updated in registers, which are synchronized with the clock signal. The state machine ensured a smooth transition between colors, creating a colour cycle visual effect on the VGA screen.

               <p> The ColourStripes module generated vertical color stripes across the VGA display. Based on the horizontal pixel position, the module assigned different RGB values to create distinct color bands. The stripe colors occupied fixed-width sections of the screen. The ColourStripes module gave me the knowledge of how to utilise rows and columns to design certain shapes and patterns on the VGA screen.

               <p> Both template modules relied on the fundamentals of the VGA interface, which used synchronization signals (HSYNC and VSYNC) and pixel clock timing to control the display. Investigating the template modules, I was then able to begin altering and designing my own VGA design. </p>

            <h2 id="simulation">Simulation</h2>
            <p>The simulation process involves running the Verilog design through a testbench to observe and verify its behavior. The screenshots below, show waveform and value traces for signals such as row, col, and RGB outputs (red, green, blue). The simulation highlights how these values evolve over time, as driven by the clk and rst signals.

               <p> The waveforms show the proper functioning of the module's color generation and state transitions. For example, the row and col signals increment appropriately, representing the pixel scanning of the VGA interface. The RGB signals (red, green, blue) remained synchronized with the logic and the VGA pixel clock, confirming the correct rendering of colors on a simulated display. Key parameters like HDISP and VDISP are instrumental in defining the active display region, as shown in the traces.</p>
               <div style="display: flex; gap: 20px; justify-content: center;">
                <img src="https://raw.githubusercontent.com/AlexP8on7/FPGA_VGA_SOC_Project/main/images/Sim2.png" alt="Simulation Screenshot 1" style="width: 60%;">
                <img src="https://raw.githubusercontent.com/AlexP8on7/FPGA_VGA_SOC_Project/main/images/Sim4.png" alt="Simulation Screenshot 2" style="width: 40%;">
            </div>
            <h2 id="synthesis">Synthesis</h2>
            <p>The synthesis and implementation processes are key stages in digital design and FPGA development.This part optimizes the design for area, speed, and power while preserving functionality. Vivado performed logic minimization and mapping that results in a gate-level representation of the design.

        
               <p> Implementation takes the synthesized netlist and maps it to the physical resources of the FPGA. This includes:
                
              <p>Placement: Assigning logical components to specific locations on the FPGA.
                <p> Routing: Establishing signal connections between components, adhering to timing and resource constraints.
                    <p> Bitstream Generation: Creating a configuration file to program the FPGA.
                        <p>The uploaded screenshot below, shows the implementation stage of the floorplan view of the FPGA with resource allocation across different regions (e.g., "X0Y0", "X1Y1"). Each colored grid represents a distinct area used for logic or routing.</p>
                        <div style="display: flex; gap: 20px; justify-content: center;">
                            <img src="https://raw.githubusercontent.com/AlexP8on7/FPGA_VGA_SOC_Project/main/images/Device.png" alt="Simulation Screenshot 1" style="width: 20%;">
                        </div>

            <h2 id="vga-design">My VGA Design Edit</h2>
         
            <p>My initial idea was to print the four letters of my first name (A, L, E, X). After editing and learning how to use the state machine, I decided to use this technique along with methods utilized in the ColourStripes module to cycle through the four letters. By integrating the state machine, I was able to control the transitions between the letters systematically, ensuring smooth and predictable operation. Additionally, I incorporated features from the ColourStripes module, such as color-cycling and timing logic, to make the display more visually appealing and dynamic. This combination of techniques allowed me to create an interactive and engaging output that effectively demonstrates my understanding of these concepts. </p>

            <h2 id="code-adaptation">Code Adaptation</h2>
            <p>The original code implements a simple colour-cycling state machine, transitioning through eight states, each representing a uniform screen color (e.g., BLACK, RED, GREEN). The state transitions are controlled by a counter, and the RGB outputs are derived from a 12-bit colour register. The design focuses on basic state machine logic and uniform VGA colour rendering.

             <p> The adapted code extends this concept to render the letters "A", "L", "E", and "X" on a VGA display. It introduces a coordinate-based rendering approach using the row and col inputs to define pixel regions for each letter. Each state corresponds to a letter, and specific colours are assigned to different letters (e.g., red for "A", green for "L"). The counter was reused for timing transitions, but the logic integrates dynamic shapes instead of regular colours. This adaptation transforms the original design from a basic colour display into a  text-rendering system.
            <p>My adapted code significantly builds on the original ColourCycle module, transforming the basic colour-cycling demonstration into a visually engaging project that combines text rendering, state machine logic, and VGA signal handling.</p>
            <div style="display: flex; gap: 10px; justify-content: center;">
                <img src="https://raw.githubusercontent.com/AlexP8on7/FPGA_VGA_SOC_Project/main/images/CodePt1.png" alt="Simulation Screenshot 1" style="width: 40%;">
                <img src="https://raw.githubusercontent.com/AlexP8on7/FPGA_VGA_SOC_Project/main/images/CodePt2.png" alt="Simulation Screenshot 1" style="width: 40%;">
                <img src="https://raw.githubusercontent.com/AlexP8on7/FPGA_VGA_SOC_Project/main/images/CodePt3.png" alt="Simulation Screenshot 1" style="width: 40%;"></div>

            <h2 id="final-demonstration">Final Demonstration</h2> 
            <p>The final demo successfully displayed the state machine cycling through the letters "A," "L," "E," and "X" on the VGA screen, showcasing precise synchronization and timing. I feel like this highlighted my custom ability to control patterns and characters dynamically.</p>
            <div style="display: flex; gap: 10px; justify-content: center;">
                <img src="https://raw.githubusercontent.com/AlexP8on7/FPGA_VGA_SOC_Project/main/images/A.png" alt="Simulation Screenshot 1" style="width: 30%;">
                <img src="https://raw.githubusercontent.com/AlexP8on7/FPGA_VGA_SOC_Project/main/images/L.png" alt="Simulation Screenshot 1" style="width: 40%;">
                <img src="https://raw.githubusercontent.com/AlexP8on7/FPGA_VGA_SOC_Project/main/images/E.png" alt="Simulation Screenshot 1" style="width: 40%;">
                <img src="https://raw.githubusercontent.com/AlexP8on7/FPGA_VGA_SOC_Project/main/images/X.png" alt="Simulation Screenshot 1" style="width: 40%;"></div>