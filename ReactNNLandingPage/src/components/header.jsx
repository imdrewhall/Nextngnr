import React, { Component } from "react";

export class Header extends Component {
  render() {
    return (
      <header id="header">
        <div className="intro">
          <div className="overlay">
            <div className="container">
              <div className="row">
                <div className="col-xs-12 col-md-8 col-md-offset-2 intro-text">
                  <h1>
                    {this.props.data ? this.props.data.title : "Loading"}
                    <span></span>
                  </h1>
                  <p>
                    {this.props.data ? this.props.data.paragraph : "Loading"}
                  </p>
                  <a
                    href="https://elearning.nextngnr.com/"
                    className="btn btn-custom btn-lg page-scroll"
                  >
                    Sitio de eLearning
                  </a>{" "}
                  <p>
                    {this.props.data ? this.props.data.paragraph2 : "Loading"}
                  </p>
                </div>
              </div>
            </div>
          </div>
        </div>
      </header>
    );
  }
}

export default Header;
