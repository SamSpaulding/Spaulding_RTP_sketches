console.log('hi friends')

APP_WIDTH = 640
APP_HEIGHT = 640
GRID_DIMENSION = 8
BLOCK_DIMENSION = 40
GRID_OFFSET = 20
SPACE_BETWEEN_BLOCKS = 25
TIME_BETWEEN_BLOCKS = 2
TIME_BETWEEN_COMPOSITES = 30

const app = new PIXI.Application({
    width: 1280,
    height: 720,
    backgroundColor: 0xFFFFFF,
    antialias: true
});
document.body.appendChild(app.view);

const draw = () => {
    app.render();
};

const style = new PIXI.TextStyle({
    fontFamily: 'Helvetica',
    fontSize: 16,
    // fontStyle: 'italic',
    fontWeight: 'bold',
    fill: ['#000000'], //'#00ff99'], // gradient
    // stroke: '#4a1850',
    // strokeThickness: 5,
    // dropShadow: true,
    // dropShadowColor: '#000000',
    // dropShadowBlur: 4,
    // dropShadowAngle: Math.PI / 6,
    // dropShadowDistance: 6,
    wordWrap: true,
    wordWrapWidth: 440
});

class PerturbedCubes {


    constructor () {
      
        draw();
        setInterval(draw, 100);

        this.grid = [];
        this.addSquare(0, true); //Add the first block to the grid
        //console.log(MathUtils.getPrimesLessThan(100))

    }

    addSquare(i, keepAddingBlocks) {
        
        let x = i % GRID_DIMENSION
        let y = Math.floor(i / GRID_DIMENSION)


        try {
            this.grid[x][y] = new PIXI.Graphics()
        } catch (error) {
            this.grid[x] = []
            this.grid[x][y] = new PIXI.Graphics()
        }
      
        this.grid[x][y].lineStyle(2, 0x000000, 1);
        // this.grid[x][y].beginFill(0x000000, 0);
        
        let xs = []
        let ys = []

        // loop to generate the random offsets for each corner and whether its offset at all
        for (let i=0; i < 4; i++) {
            let dscale = (Math.random() + 1) * 2 // +1 offsets it so we dont divide by a decimal
            let dx = Math.random() * BLOCK_DIMENSION / dscale
            let dy = Math.random() * BLOCK_DIMENSION / dscale
            
            switch(i) {
                case 0:
                    xs.push(x + (Math.round(Math.random()))*dx)
                    ys.push(y + (Math.round(Math.random()))*dy)
                    break;
                case 1:
                    xs.push(x+BLOCK_DIMENSION + (Math.round(Math.random()))*dx)
                    ys.push(y + (Math.round(Math.random()))*dy)
                    break;
                case 2:
                    xs.push(x+BLOCK_DIMENSION + (Math.round(Math.random()))*dx)
                    ys.push(y+BLOCK_DIMENSION + (Math.round(Math.random()))*dy)
                    break;
                case 3:
                    xs.push(x + (Math.round(Math.random()))*dx)
                    ys.push(y+BLOCK_DIMENSION    + (Math.round(Math.random()))*dy)
                    break;                
            }            
            // console.log(dx)
            // console.log(dy)
            // console.log(dscale)
            // console.log("------")
        }
        console.log(xs)

        //move to initial drawing point
        this.grid[x][y].moveTo(xs[0], ys[0])

        // For loop to actually do the line drawing
        for (let i=1; i < 5; i++) {
            this.grid[x][y].lineTo(xs[i%4], ys[i%4])            
        }

        // map from X Y grid index to actual PIXI coordinates
        this.grid[x][y].position.set(GRID_OFFSET + (x * (BLOCK_DIMENSION+SPACE_BETWEEN_BLOCKS)), GRID_OFFSET + (y * (BLOCK_DIMENSION+SPACE_BETWEEN_BLOCKS)))

        // add text label to each square
        // let label = new PIXI.Text(i+1, style);
        // label.anchor.set(0.5, 0.5)
        // label.position.set(this.grid[x][y].x + BLOCK_DIMENSION/2, this.grid[x][y].y + BLOCK_DIMENSION/2)

        // this.grid[x][y].addChild(label)

        //console.log(i,x,y)
        //console.log(this.grid[x][y].x, this.grid[x][y].y)
        app.stage.addChild(this.grid[x][y])
        // app.stage.addChild(label)

        // if we haven't finished generating the whole grid yet, wait 500s then add a new block
        if (i < (GRID_DIMENSION**2 - 1) && keepAddingBlocks) {
            //console.log("setting timeout for iteration " + (i+1))            
            setTimeout(this.addSquare.bind(this), TIME_BETWEEN_BLOCKS, i+1, keepAddingBlocks);
        }        
    }
}




let myCubes = new PerturbedCubes()