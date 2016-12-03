
cylinder(h=5, d=70);

difference() {
    cylinder(h=5, d=140);
    translate([0, 0, -1]) cylinder(h=7, d=120);
}


 translate([30, -30, 2.5]) rotate([0, 0, 45]) cube([15, 60, 5], center=true);
 translate([-30, -30, 2.5]) rotate([0, 0, 135]) cube([15, 60, 5], center=true); 
translate([0, 30, 2.5]) rotate([0, 0, 0]) cube([15, 75, 5], center=true);


translate([-47, -47, 0]) {
    difference() {
        union() {
            cylinder(h=5, d=30);
            cylinder(h=12, d=10);
        }
        translate([0, 0, -1]) cylinder(h=14, d=4);
    }
    
}

translate([47, -47, 0]) {
    cylinder(h=5, d=30);
    cylinder(h=12, d=10);
}


// pipe
    
pipe_length     = 150;
pipe_diameter   = 36;
cutout_length   = 70;

translate([0, 0, 0]) rotate([0, 0, 0]) {
    
    difference() {
        union() {
            cylinder(h=pipe_length, d=pipe_diameter, $fn=64);
            
            translate([-10/2, -(pipe_diameter/2 + 10), 50]) cube([10, 10, 25]);         
            translate([0, -(pipe_diameter/2)+3, 70]) rotate([90, 0, 0]) cylinder(h=13, d=20);
            translate([5, -10-pipe_diameter/2, 50]) rotate([0, 180, 0]) prism(10, 10, 10);
        }
        translate([0, 0, -1]) cylinder(h=pipe_length+2, d=pipe_diameter-6, $fn=64);
        translate([-pipe_diameter/2, -pipe_diameter, pipe_length-cutout_length+1]) cube([ pipe_diameter, pipe_diameter, cutout_length+1]);
        
        // pen screw nudge
        translate([0, -77.5, 70]) sphere(d=100, $fn=128);
        
        // pen screw hole
        translate([0, 0, 70]) rotate([90, 0, 0])cylinder(h=30, d=5);
    }
}

// -------------------------------------------------------------

module prism(l, w, h){
    polyhedron(points=[[0,0,0], [l,0,0], [l,w,0], [0,w,0], [0,w,h], [l,w,h]], faces=[[0,1,2,3],[5,4,3,2],[0,4,5,1],[0,3,4],[5,2,1]]);
}
