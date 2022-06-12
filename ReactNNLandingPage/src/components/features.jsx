import React, { Component } from "react";
import Tilt from "react-tilt";
import AppFeatures from "./AppFeatures";
import {
    BrowserRouter as Router,
    Switch,
    Route,
    Link
  } from "react-router-dom";

export class features extends Component {
  render() {
    return (
      <div id="features" className="text-center">
        <div className="container">
          <div className="col-md-10 col-md-offset-1 section-title">
            <h2>Nuestros Pilares</h2>
          </div>
          <div className="row">
            {this.props.data
              ? this.props.data.map((d,i) => (
                  <div  key={`${d.title}-${i}`} className="col-xs-12 col-md-3">
                    {" "}
                    <div className="testimonial-image2">
                        {" "}
                        <Tilt className="Tilt" options={{ max : 10 }}  >
                      <div className="Tilt-inner"> <img src={d.img} alt="" /> </div>
                      </Tilt> 
                        {" "}
                      </div>
                    <h3>{d.title}</h3>
                    <p>{d.text}</p>
                    {/* <a
                    href="#features"
                    className="btn btn-custom btn-lg page-scroll"
                  >
                    Saber Más
                  </a>{" "} */}
                  </div>
                ))
              : "Loading..."}
          </div>
           <div className="col-md-10 col-md-offset-1">
               {/* <h2> 
                <Router>
                  <div>
                    <nav>                        
                            <Link to="/nextngnrwp/appfeatures">Home</Link>
                    </nav> */}
            
                    {/* A <Switch> looks through its children <Route>s and
                        renders the first one that matches the current URL. */}
                    {/* <Switch>
                        <Route path="/nextngnrwp/appfeatures">
                        <AppFeatures />
                        </Route>
                    </Switch>
                  </div>
                </Router>
              </h2> */}
            </div>
        </div>
      </div>
    );
  }
}

export default features;
