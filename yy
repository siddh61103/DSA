mkdir bfhl-api
cd bfhl-api


npm init -y


npm install express body-parser


touch index.js


const express = require('express');
const bodyParser = require('body-parser');

const app = express();
const port = process.env.PORT || 3000;

// Middleware
app.use(bodyParser.json());

// POST endpoint to handle the array data
app.post('/bfhl', (req, res) => {
    try {
        const { data } = req.body;

        // Mock user data
        const user = {
            user_id: "john_doe_17091999",
            email: "john@xyz.com",
            roll_number: "ABCD123"
        };

        // Logic to separate even numbers, odd numbers, and alphabets
        const evenNumbers = data.filter(num => num % 2 === 0 && !isNaN(num));
        const oddNumbers = data.filter(num => num % 2 !== 0 && !isNaN(num));
        const alphabets = data.filter(item => isNaN(item)).map(item => item.toUpperCase());

        // Construct response
        const response = {
            is_success: true,
            user_id: user.user_id,
            email: user.email,
            roll_number: user.roll_number,
            even_numbers: evenNumbers,
            odd_numbers: oddNumbers,
            alphabets: alphabets
        };

        res.json(response);
    } catch (error) {
        console.error("Error:", error);
        res.status(500).json({ is_success: false, error: "Internal server error" });
    }
});

// Start the server
app.listen(port, () => {
    console.log(`Server is running on http://localhost:${port}`);
});






Sure, I'll guide you through the whole process step by step, including setting up the project, writing the code, testing it locally, and deploying it to Heroku.

Step 1: Set Up the Project

Create a new directory for your project.
bash
Copy code
mkdir bfhl-api
cd bfhl-api
Initialize a new Node.js project.
bash
Copy code
npm init -y
Install the necessary dependencies: Express and body-parser.
bash
Copy code
npm install express body-parser
Step 2: Write the Code

Create a new file named index.js in your project directory.
bash
Copy code
touch index.js
Open index.js in a text editor and paste the following code:
javascript
Copy code
const express = require('express');
const bodyParser = require('body-parser');

const app = express();
const port = process.env.PORT || 3000;

// Middleware
app.use(bodyParser.json());

// POST endpoint to handle the array data
app.post('/bfhl', (req, res) => {
    try {
        const { data } = req.body;

        // Mock user data
        const user = {
            user_id: "john_doe_17091999",
            email: "john@xyz.com",
            roll_number: "ABCD123"
        };

        // Logic to separate even numbers, odd numbers, and alphabets
        const evenNumbers = data.filter(num => num % 2 === 0 && !isNaN(num));
        const oddNumbers = data.filter(num => num % 2 !== 0 && !isNaN(num));
        const alphabets = data.filter(item => isNaN(item)).map(item => item.toUpperCase());

        // Construct response
        const response = {
            is_success: true,
            user_id: user.user_id,
            email: user.email,
            roll_number: user.roll_number,
            even_numbers: evenNumbers,
            odd_numbers: oddNumbers,
            alphabets: alphabets
        };

        res.json(response);
    } catch (error) {
        console.error("Error:", error);
        res.status(500).json({ is_success: false, error: "Internal server error" });
    }
});

// Start the server
app.listen(port, () => {
    console.log(`Server is running on http://localhost:${port}`);
});
Step 3: Test Locally

Start the server locally.
bash
Copy code
node index.js
Open another terminal window and send a POST request to test the endpoint using curl or any REST client like Postman.
bash
Copy code
curl -X POST -H "Content-Type: application/json" -d '{"data":["a","1","334","4","R"]}' http://localhost:3000/bfhl
You should receive a response similar to the example responses provided.

Step 4: Deploy to Heroku

Create a new file named Procfile in your project directory.
bash
Copy code
touch Procfile
Open Procfile in a text editor and add the following line:
makefile
Copy code
web: node index.js
Initialize a new Git repository in your project directory.
bash
Copy code
git init
Add and commit your files to the repository.
bash
Copy code
git add .
git commit -m "Initial commit"
Install the Heroku CLI if you haven't already.

Log in to your Heroku account using the CLI.

bash
Copy code
heroku login
Create a new Heroku app.
bash
Copy code
heroku create
Deploy your code to Heroku.
bash
Copy code
git push heroku master
Once the deployment is complete, open the app in your browser.
bash
Copy code
heroku open
Test the endpoint using the Heroku app URL.
Step 5: Submission

Fill out the form provided with the URL of your deployed Heroku app.
And that's it! You've built and deployed a REST API that meets the specified requirements.






